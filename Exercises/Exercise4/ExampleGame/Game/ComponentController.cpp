#pragma once

#include "ComponentController.h"
#include "Bullet.h"
#include "Engine/MyEngine.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <iostream>
#include "ComponentRendererSprite.h"
#include "sre/SpriteAtlas.hpp"


namespace ExampleGame {
	ComponentController::ComponentController(std::shared_ptr<sre::SpriteAtlas> atlas, MyEngine::Engine* engine)
		: atlas(atlas), engine(engine) {}

	void ComponentController::Init() {}

	void ComponentController::Update(float deltaTime) {
		// Use the engine instance already passed in
		MyEngine::GameObject* parent = GetGameObject();
		glm::vec2 basePos = engine->GetScreenSize() / 2.f;
	}

	void ComponentController::KeyEvent(SDL_Event& event) {
		MyEngine::GameObject* parent = GetGameObject();

		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w: {
				// Handle movement
				float angleRad = glm::radians(parent->rotation);
				glm::vec2 direction = glm::vec2(glm::sin(angleRad), -glm::cos(angleRad));
				parent->position += direction * MovSpeed;
				break;
			}
			case SDLK_a: {
				parent->rotation += RotSpeed;
				break;
			}
			case SDLK_d: {
				parent->rotation -= RotSpeed;
				break;
			}
			case SDLK_SPACE: {
				ShootBullet();
				break;
			}
			default:
				break;
			}
		}
	}

	void ComponentController::ShootBullet() {
		MyEngine::GameObject* parent = GetGameObject();

		// Create a new bullet object
		auto bullet = std::make_shared<Bullet>();

		// Set bullet's position to parent's position
		bullet->position = parent->position;

		// Set bullet's direction based on parent's rotation
		float angleRad = glm::radians(parent->rotation);
		glm::vec2 direction = glm::vec2(glm::cos(angleRad), glm::sin(angleRad));
		bullet->SetDirection(direction);

		// Attach a sprite renderer to the bullet
		auto bulletRenderer = std::make_shared<ComponentRendererSprite>();
		bulletRenderer->sprite = atlas->get("beam0.png");
		bullet->AddComponent(bulletRenderer);

		// Add the bullet to the game world
		parent->AddChild(bullet);

		std::cout << "Bullet shot at position: (" << bullet->position.x << ", " << bullet->position.y << ")" << std::endl;
	}
}