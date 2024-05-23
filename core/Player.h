#pragma once
#include "Base.h"
#define MAX_SHOOTS 50


class Player {
public:

    void Init();
    void Update();
    Rectangle& GetPlayerModel();
    Vector2 GetPlayerSpeed();
    int GetHealth();
    Color GetColor();
    void SetHealth(int health);
    void UnloadPlayerTexture();
    Texture2D GetTexture();
    Vector2& GetPlayerPosition();
    int GetScore();
    void SetScore(int score);
    void Shoot();
    int GetAmmo();
    void SetAmmo(int ammo);
    int GetNumShoots() const { return NUM_SHOOTS; }

    bool GetShootActive(int index) const { return shootActive[index]; }
    void SetShootActive(int index, bool active) { shootActive[index] = active; }

    Rectangle GetShootModel(int index) const { return shootModels[index]; }
    void SetShootModel(int index, const Rectangle& model) { shootModels[index] = model; }

private:
    Rectangle playerDebugModel;
    Vector2 speed;
    Color color;
    int health = 3;
    Texture2D shipTexture;
    Vector2 position;
    int score = 0;
    int ammo = 20;

    // Shooting vars
    static const int NUM_SHOOTS = 50;
    Rectangle shootModels[NUM_SHOOTS];
    Vector2 shootSpeed;
    bool shootActive[NUM_SHOOTS];
    Color shootColor;
    int shootRate;
};