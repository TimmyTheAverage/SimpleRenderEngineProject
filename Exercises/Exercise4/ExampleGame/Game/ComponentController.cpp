#include "ComponentController.h"
#include <cmath>
#include "Engine/MyEngine.h"

namespace ExampleGame {
	void ComponentController::Init() {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		glm::vec2 basePos = engine->GetScreenSize() / 2.f;
		parent->position = basePos;
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		// Update rotation
		parent->rotation += RotSpeed * deltaTime * rotationDirection;

		// Convert rotation angle to direction vector subtracting 90 degrees (π/2 radians)
		float angleInRadians = glm::radians(parent->rotation) - M_PI / 2.0f;
		glm::vec2 direction(cos(angleInRadians), sin(angleInRadians));

		// Update position
		parent->position += direction * MovSpeed * deltaTime * acceleration;

		if (parent->position.x > engine->GetScreenSize().x + 25) {
			parent->position.x = -25;
		}
		else if (parent->position.y > engine->GetScreenSize().y + 25) {
			parent->position.y = -25;
		}
		else if (parent->position.x < -25) {
			parent->position.x = engine->GetScreenSize().x + 25;
		}
		else if (parent->position.y < -25) {
			parent->position.y = engine->GetScreenSize().y + 25;
		}
	}

	void ComponentController::KeyEvent(SDL_Event& event) {
		MyEngine::GameObject* parent = GetGameObject();

		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				acceleration = 1;
				break;
			case SDLK_s:
				acceleration = -1;
				break;
			case SDLK_a:
				rotationDirection = 1;
				break;
			case SDLK_d:
				rotationDirection = -1;
				break;
			case SDLK_SPACE:
				//instansiate laser
					
				break;
			}
		}

		else if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				acceleration = 0;
				break;
			case SDLK_s:
				acceleration = 0;
				break;
			case SDLK_a:
				rotationDirection = 0;
				break;
			case SDLK_d:
				rotationDirection = 0;
				break;
			}
		}
	}
}