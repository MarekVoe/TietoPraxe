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
                renderer.RenderMenu(gameScene);
            break;

            case GameScene::SCENE_MAIN:
                renderer.RenderGame(player);
            break;
        }
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    player.UnloadPlayerTexture();
}