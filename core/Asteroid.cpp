#include "Asteroid.h"

void Asteroid::Init(Vector2 startPos, Vector2 startSpeed, Color color) {
    asteroidTexture = LoadTexture("../assets/MeteoriteSprite.png");
    asteroidModel = {startPos.x, startPos.y, 30,30};
    speed = startSpeed;
    this->color = color;
    active = true;
}

void Asteroid::Update(Player& player) {
    if (!active)
        return;

    asteroidModel.x += speed.x;

    if (asteroidModel.x + asteroidModel.width < 0) {
        active = false;
        UnloadTexture(asteroidTexture);
        player.SetScore(player.GetScore() + 2);
    }
}

Rectangle Asteroid::GetAsteroidModel() {
    return this->asteroidModel;
}

void Asteroid::Draw() const {
    if (active) {
        Rectangle sourceRect = {0.0f, 0.0f, (float) asteroidTexture.width, (float) asteroidTexture.height};
        Vector2 position = {asteroidModel.x, asteroidModel.y};
        DrawTextureRec(asteroidTexture, sourceRect, position, color);
    }
}

void Asteroid::SetInactive() {
    active = false;
    UnloadTexture(asteroidTexture);
}

Vector2 Asteroid::GetAsteroidPosition() {
    return { asteroidModel.x, asteroidModel.y };
}
