// Asteroid.h
#pragma once
#include "Engine/GameObject.h"

class Asteroid : public MyEngine::GameObject {
public:
    Asteroid();
    void Init();
    void Update(float deltaTime) override;

private:
    float speed;
    float lifetime;
};
