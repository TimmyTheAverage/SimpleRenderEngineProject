#include "ComponentController.h"

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

		parent->rotation += RotSpeed * deltaTime * rotationDirection;
		parent->position += MovDirection * MovSpeed * deltaTime * acceleration;
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