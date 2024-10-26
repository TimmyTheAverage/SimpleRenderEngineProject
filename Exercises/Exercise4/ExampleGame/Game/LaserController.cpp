#include "LaserController.h"
#include "LaserMovement.h"
#include "ComponentRendererSprite.h"
#include <cmath>
#include "Engine/MyEngine.h"

namespace ExampleGame {
	void LaserController::Init() {
		atlas = sre::SpriteAtlas::create("data/astroids.json", "data/astroids.png");
	}

	void LaserController::KeyEvent(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
			MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
			MyEngine::GameObject* parent = GetGameObject();

			auto gameObject = engine->CreateGameObject("Laser");
			// laser position is the same as the parent position
			gameObject->position = parent->position;
			gameObject->rotation = parent->rotation;

			auto laserController = std::make_shared<LaserMovement>();
			auto laserRenderer = std::make_shared<ComponentRendererSprite>();
			gameObject->AddComponent(laserController);
			gameObject->AddComponent(laserRenderer);

			laserRenderer->sprite = atlas->get("enemyBlue3.png");
		}
	}
}	