#include "Bullet.h"
#include "Engine/MyEngine.h"
#include "GameObject.h"
#include "Engine/GameObject.h"
#include <iostream>
#include <glm/glm.hpp>
#include <SDL.h>
#include "Engine/Component.h"

//make bullet go pew pew
void Bullet::Init() {
	//std::cout << "Bullet Init" << std::endl;
}

void Bullet::Update(float deltaTime) {
	//std::cout << "Bullet Update" << std::endl;
	MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
	MyEngine::GameObject* parent = GetGameObject();
	lifetime += deltaTime;
	if (lifetime > 2.0f) {
		
		parent->MarkedForDeletion = true;
		
	}
	// Get direction from parent
	// Handle movement
	float angleRad = glm::radians(parent->rotation);
	glm::vec2 direction = glm::vec2(glm::sin(angleRad), -glm::cos(angleRad));
	// Move bullet
	parent->position += direction * speed * deltaTime;
}
