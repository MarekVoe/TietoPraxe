#pragma once
#include "Base.h"
#include "Player.h"

class Enemy {
public:
    void Init(Vector2 startPos, Vector2 startSpeed, Color color);
    void Draw();
    bool IsActive();
    void Shoot(Player& player);
    void Update(Player& player);
private:
    Rectangle enemyModel;
    Vector2 speed;
    Color color;
    bool active;
    Texture2D enemyTexture;

    static const int NUM_SHOOTS = 10;
    Rectangle shootModels[NUM_SHOOTS];
    Vector2 shootSpeed;
    bool shootActive[NUM_SHOOTS];
    Color shootColor;
    int shootRate;
};