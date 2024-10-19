#pragma once
#include "Engine/GameObject.h"
#include <glm/glm.hpp>

class Bullet : public MyEngine::GameObject {
public:
    void SetPosition(const glm::vec2& pos) {
        position = pos;
    }

    void SetDirection(const glm::vec2& dir) {
        direction = dir;
    }

    void Update(float deltaTime) override {
        position += direction * speed * deltaTime;
    }

    void KeyEvent(SDL_Event& event) override {
        // Handle key events if needed
    }

private:
    glm::vec2 direction;
    float speed = 200.0f; // Adjust the speed as needed
};
