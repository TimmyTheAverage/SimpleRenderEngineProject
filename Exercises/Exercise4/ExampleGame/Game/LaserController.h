#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class LaserController : public MyEngine::Component {
	private:
		std::shared_ptr<sre::SpriteAtlas> atlas;
	public:
		void Init() override;
		void KeyEvent(SDL_Event&) override;
	};
}