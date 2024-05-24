#include <algorithm>
#include <iostream>
#include "AsteroidManager.h"


void AsteroidManager::Init() {
    srand(time(NULL));
}

bool AsteroidManager::CheckAsteroidCollision(Player& player, Asteroid& asteroid) {
    Vector2 playerPos = player.GetPlayerPosition();
    Rectangle playerModel = player.GetPlayerModel();
    Rectangle playerRect = { playerPos.x, playerPos.y, playerModel.width, playerModel.height };

    Vector2 asteroidPos = asteroid.GetAsteroidPosition();
    Rectangle asteroidModel = asteroid.GetAsteroidModel();
    Rectangle asteroidRect = { asteroidPos.x, asteroidPos.y, asteroidModel.width, asteroidModel.height };

    return CheckCollisionRecs(playerRect, asteroidRect);
}



void AsteroidManager::Update(Player& player) {
    spawnCounter++;
    if (spawnCounter >= spawnRate) {
        spawnCounter = 0;

        Vector2 position = {(float) GetScreenWidth(), (float) (rand() % GetScreenHeight())};
        Vector2 speed = {-5.0f, 0.0f};

        Asteroid asteroid;
        asteroid.Init(position, speed, WHITE);
        asteroids.push_back(asteroid);
    }

    for(auto& asteroid : asteroids) {
        asteroid.Update(player);

        if (CheckAsteroidCollision(player, asteroid) && asteroid.IsActive()) {
            asteroid.SetInactive();
            player.SetHealth(player.GetHealth() - 1);
        }
    }

    asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [](Asteroid& a) { return !a.IsActive(); }), asteroids.end());
}

void AsteroidManager::Draw() {
    for(const auto& asteroid : asteroids) {
        asteroid.Draw();
    }
}