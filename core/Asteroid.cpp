#include "Asteroid.h"

void Asteroid::Init() {
    asteroidTexture = LoadTexture("../assets/MeteoriteSprite.png");
    spawnPos = {(float) GetRandomValue(0, 1280), (float) GetRandomValue(0, 720) };
}

void Asteroid::UnloadAsteroidTexture() {
    UnloadTexture(asteroidTexture);
}

Texture2D Asteroid::GetAsteroidTexture() {
    return this->asteroidTexture;
}

int Asteroid::GetSpeed() {
    return this->speed;
}

void Asteroid::SetSpeed(int speed) {
    this->speed = speed;
}

Vector2 Asteroid::GetSpawnPos() {
    return this->spawnPos;
}