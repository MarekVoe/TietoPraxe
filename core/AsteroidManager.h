#pragma once
#include "Base.h"
#include "Asteroid.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class AsteroidManager {
public:
    void Init();
    void Update(Player& player);
    void Draw();
    bool CheckAsteroidCollision(Player& player, Asteroid& asteroid);
private:
    std::vector<Asteroid> asteroids;
    int spawnRate = 120;
    int spawnCounter = 0;
};