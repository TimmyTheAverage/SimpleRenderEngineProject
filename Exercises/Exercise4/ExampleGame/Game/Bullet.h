#pragma once
#include "Engine/GameObject.h"
#include <glm/glm.hpp>
#include <SDL.h>
#include <iostream>
#include "Engine/Component.h"

class Bullet : public MyEngine::Component {
public:
    void Init() override;
    void Update(float deltaTime) override;
	const float speed = 300.0f;

private:
	float lifetime = 0.0f;
};