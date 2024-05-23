#pragma once
#include "Base.h"

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
private:
    Rectangle playerDebugModel;
    Vector2 speed;
    Color color;
    int health = 3;
    Texture2D shipTexture;
    Vector2 position;
    int score = 0;
};