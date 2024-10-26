#include "LaserMovement.h"
#include <cmath>
#include "Engine/MyEngine.h"

namespace ExampleGame {
	void LaserMovement::Init() {
		
	}

	void LaserMovement::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();
		
		// Convert rotation angle to direction vector subtracting 90 degrees (π/2 radians)
		float angleInRadians = glm::radians(parent->rotation) - M_PI / 2.0f;
		glm::vec2 direction(cos(angleInRadians), sin(angleInRadians));

		// Update position
		parent->position += direction * LaserSpeed * deltaTime;

		// Destroy laser if it out of time
		laserDeathTime += deltaTime;
		if (laserDeathTime > 1) {
			parent->LowTierGod = true;
		}
	}
}