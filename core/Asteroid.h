#pragma once
#include "Base.h"
#include "Player.h"

class Asteroid {
public:
    void Init(Vector2 startPos, Vector2 startSpeed, Color color);
    void Update(Player& player);
    void Draw() const;
    bool IsActive() const { return active; }
    Rectangle GetAsteroidModel();
    Vector2 GetAsteroidPosition();
    void SetInactive();
private:
    Rectangle asteroidModel;
    Vector2 speed;
    Color color;
    bool active;
    Texture2D asteroidTexture;
};