#pragma once

#include "Engine/Component.h"
#include "Engine/MyEngine.h"
#include <SDL.h>
#include "sre/SpriteAtlas.hpp"
#include "sre/Sprite.hpp"
namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		const float RotSpeed = 50;
		const float MovSpeed = 5;
		const float MovAmount = 20;
		const glm::vec2 MovDirection = glm::vec2(1, 0);

	public:
		glm::vec2 position;
		float rotation;

		std::shared_ptr<sre::SpriteAtlas> atlas;
		MyEngine::Engine* engine;

		ComponentController(std::shared_ptr<sre::SpriteAtlas> atlas, MyEngine::Engine* engine);

		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event&) override;

	private:
		void ShootBullet();
	};
}