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
    asteroidManager = AsteroidManager();
    asteroidManager.Init();
    Update();
}


void Window::Update() {
    while(!WindowShouldClose()) {
        inputManager.Update(player);
        BeginDrawing();
        player.Update(gameScene);
        switch(gameScene.GetCurrentScene()) {
            case GameScene::SCENE_MENU:
                renderer.RenderMenu(gameScene);
            break;

            case GameScene::SCENE_MAIN:
                renderer.RenderGame(player);
                asteroidManager.Update(player);
                asteroidManager.Draw();
            break;

            case GameScene::SCENE_GAME_OVER:
                renderer.RenderGameOver(gameScene);
            break;
        }
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    player.UnloadPlayerTexture();
}