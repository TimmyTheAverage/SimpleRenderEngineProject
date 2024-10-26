#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class LaserMovement : public MyEngine::Component {
		const float LaserSpeed = 300;

	public:
		glm::vec2 position;
		float rotation;

		void Init() override;
		void Update(float) override;

	private:
		float laserDeathTime = 0;
	};
}