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
				glm::vec2 direction = glm::vec2(glm::cos(angleRad), glm::sin(angleRad));
				parent->position += direction * MovSpeed;
				break;
			}
			case SDLK_a: {
				parent->rotation -= RotSpeed;
				break;
			}
			case SDLK_d: {
				parent->rotation += RotSpeed;
				break;
			}
			case SDLK_s: {
				float angleRad = glm::radians(parent->rotation);
				glm::vec2 direction = glm::vec2(glm::cos(angleRad), glm::sin(angleRad));
				parent->position -= direction * MovSpeed;
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
		std::cout << "Shoot Bullet" << std::endl;
		MyEngine::GameObject* parent = GetGameObject();
		auto bullet = std::make_shared<Bullet>();

		// Set bullet's initial position to parent's position
		bullet->SetPosition(parent->position);

		// Set bullet's direction based on parent's rotation
		float angleRad = glm::radians(parent->rotation);
		glm::vec2 direction = glm::vec2(glm::cos(angleRad), glm::sin(angleRad));
		bullet->SetDirection(direction);

		// Attach a sprite to the bullet
		auto bulletSpriteRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
		bulletSpriteRenderer->sprite = atlas->get("bullet.png"); // Use correct bullet sprite
		bullet->AddComponent(bulletSpriteRenderer);

		// Add bullet to the parent or the game world
		parent->AddChild(bullet);
	}
}