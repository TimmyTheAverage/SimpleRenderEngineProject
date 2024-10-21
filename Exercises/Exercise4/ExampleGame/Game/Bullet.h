#pragma once
#include "Engine/GameObject.h"
#include <glm/glm.hpp>
#include <SDL.h>
#include <iostream>

class Bullet : public MyEngine::GameObject {
public:
    void Init(){}

    void Update(float deltaTime) override {
        // Move bullet in the set direction
        position += direction * speed * deltaTime;
    }

    void SetDirection(const glm::vec2& dir) {
        direction = dir;
    }

private:
    glm::vec2 direction = glm::vec2(0.0f, 0.0f);  // Direction of the bullet
    float speed = 300.0f;  // Bullet speed, can be adjusted as needed
};