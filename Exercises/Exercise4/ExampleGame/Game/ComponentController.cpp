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
		auto bullet = engine->CreateGameObject("Bullet");
		auto bulletComponent = std::make_shared<Bullet>();
		auto bulletRenderer = std::make_shared<ComponentRendererSprite>();
		bullet->AddComponent(bulletComponent);
		bullet->AddComponent(bulletRenderer);
		bullet->position = parent->position;
		bullet->rotation = parent->rotation;
		bulletRenderer->sprite = atlas->get("laserBlue01.png");
	}
}