#include <cmath>
#include <iostream>
#include "Window.h"

void Window::Init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tieto Praxe - Game");
    SetTargetFPS(60);
    gameIcon = LoadImage("../assets/GameIcon.png");
    SetWindowIcon(gameIcon);
    player = Player();
    player.Init();
    inputManager = InputManager();
    inputManager.Init();
    renderer = Renderer();
    renderer.Init();
    gameScene = GameScene();
    gameScene.Init();
    enemyManager = EnemyManager();
    enemyManager.Init(10);
    asteroidManager = AsteroidManager();
    asteroidManager.Init();
    std::cout << "Test" << std::endl;
    Update();
}


void Window::Update() {
    while(!WindowShouldClose()) {
        frameCounter++;
        inputManager.Update(player);
        BeginDrawing();
        ClearBackground(BLACK); // Přesunuto sem

        player.Update(gameScene);
        switch(gameScene.GetCurrentScene()) {
            case GameScene::SCENE_MENU:
                renderer.RenderMenu(gameScene);
                break;

            case GameScene::SCENE_MAIN:
                renderer.RenderGame(player);
                asteroidManager.Update(player);
                asteroidManager.Draw();
                /*
                enemyManager.Update(player);
                enemyManager.Draw();
                if (frameCounter >= 20) {
                    Vector2 startPos = {1280, (float) GetRandomValue(0, 720)};
                    Vector2 startSpeed = {-2.0f, 0.0f};
                    enemyManager.SpawnEnemy(startPos, startSpeed, WHITE);
                    frameCounter = 0;
                    }
                    */
                break;

            case GameScene::SCENE_GAME_OVER:
                renderer.RenderGameOver(gameScene, player);
                break;
        }

        EndDrawing();
    }
    CloseWindow();
    player.UnloadPlayerTexture();
}
