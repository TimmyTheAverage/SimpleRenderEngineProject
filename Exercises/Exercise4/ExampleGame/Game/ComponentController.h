#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		const float RotSpeed = 250;
		const float MovSpeed = 300;
		const glm::vec2 MovDirection = glm::vec2(1, 0);

	public:
		glm::vec2 position;
		float rotation;
		int rotationDirection;
		float acceleration = 0;

		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event&) override;
	};
}