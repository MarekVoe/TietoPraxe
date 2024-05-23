#pragma once
#include "Base.h"

class Asteroid {
public:
    void Init();
    int GetSpeed();
    Texture2D GetAsteroidTexture();
    void SetSpeed(int speed);
    void UnloadAsteroidTexture();
    Vector2 GetSpawnPos();
private:
    int speed = 2;
    Texture2D asteroidTexture;
    Vector2 spawnPos;
};