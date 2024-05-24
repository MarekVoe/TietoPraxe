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

bool AsteroidManager::CheckShootCollision(Player &player, Asteroid &asteroid) {
    for (int i = 0; i < player.GetNumShoots(); i++) {
        if(player.GetShootActive(i)) {
            Rectangle bulletRec = {player.GetShootModel(i).x, player.GetShootModel(i).y, player.GetShootModel(i).width, player.GetShootModel(i).height};
            Rectangle asteroidRec = asteroid.GetAsteroidModel();

            if(CheckCollisionRecs(bulletRec, asteroidRec)) {
                player.SetShootActive(i, false);
                return true;
            }
        }
    }
    return false;
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

        if (CheckShootCollision(player, asteroid) && asteroid.IsActive()) {
            asteroid.SetInactive();
            player.SetScore(player.GetScore() + 5);
            player.SetAmmo(player.GetAmmo() + 2);
            numOfDestroyedAsteroids++;
            switch(numOfDestroyedAsteroids) {
                case 10:
                    spawnRate = 60;
                    TraceLog(LOG_INFO, TextFormat("Spawn Rate set to: %d \n", spawnRate));
                break;

                case 20:
                    spawnRate = 40;
                break;

                case 30:
                    spawnRate = 20;
                break;

                case 40:
                    spawnRate = 10;
                break;
            }
        }
    }

    asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [](Asteroid& a) { return !a.IsActive(); }), asteroids.end());
}

void AsteroidManager::Draw() {
    for(const auto& asteroid : asteroids) {
        asteroid.Draw();
    }
}