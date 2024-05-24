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
    bool CheckShootCollision(Player& player, Asteroid& asteroid);
private:
    std::vector<Asteroid> asteroids;
    int spawnRate = 80;
    int spawnCounter = 0;
    int numOfDestroyedAsteroids = 0;
};