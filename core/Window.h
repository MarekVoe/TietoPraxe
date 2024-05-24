#pragma once
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#include "Base.h"
#include "Player.h"
#include "../inputs/InputManager.h"
#include "../rendering/Renderer.h"
#include "GameScene.h"
#include "AsteroidManager.h"
#include "EnemyManager.h"

class Window {
public:
    // Zde je veskery update okna, volani rendering funkci apod.
    void Update();

    // Inicializace okna
    void Init();
private:
    Player player;
    int frameCounter = 0;
    Renderer renderer;
    InputManager inputManager;
    GameScene gameScene;
    Image gameIcon;
    AsteroidManager asteroidManager;
    EnemyManager enemyManager;
};