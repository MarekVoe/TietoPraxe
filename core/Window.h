#pragma once
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#include "Base.h"

class Window {
public:
    // Zde je veskery update okna, volani rendering funkci apod.
    void Update();

    // Inicializace okna
    void Init();
private:

};