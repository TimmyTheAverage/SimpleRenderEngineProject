// Asteroid.cpp
#include "Asteroid.h"
#include <glm/glm.hpp>
#include <cstdlib>
#include <ctime>

Asteroid::Asteroid() : speed(100.0f), lifetime(0.0f) {
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(0)));
}

void Asteroid::Init() {
    // Initialize asteroid properties
}

void Asteroid::Update(float deltaTime) {
    lifetime += deltaTime;
    if (lifetime > 5.0f) {
        MarkedForDeletion = true;
    }

    // Move asteroid
    position += glm::vec2(0, speed * deltaTime);
}
