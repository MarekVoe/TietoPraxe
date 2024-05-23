#pragma once
#include "Base.h"

class Player {
public:
    void Init();
    void Update();
    Rectangle& GetPlayerModel();
    Vector2 GetPlayerSpeed();
    Color GetColor();
private:
    Rectangle playerDebugModel;
    Vector2 speed;
    Color color;
};