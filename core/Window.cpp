#include "Window.h"

void Window::Init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tieto Praxe - Game");
    SetTargetFPS(60);
    player = Player();
    player.Init();
    inputManager = InputManager();
    inputManager.Init();
    renderer = Renderer();
    gameScene = GameScene();
    gameScene.Init();
    Update();
}


void Window::Update() {

    while(!WindowShouldClose()) {
        inputManager.Update(player);
        BeginDrawing();
        player.Update();
        switch(gameScene.GetCurrentScene()) {
            case GameScene::SCENE_MENU:
                renderer.RenderMenu();
            break;

            case GameScene::SCENE_MAIN:
                renderer.RenderGame(player);
                DrawText(TextFormat("Player health: %d", player.GetHealth()),20, 10, 20, RED);
                DrawText(TextFormat("Score: %d", player.GetScore()), SCREEN_WIDTH / 2, 10,20, WHITE);
            break;
        }
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    player.UnloadPlayerTexture();
}