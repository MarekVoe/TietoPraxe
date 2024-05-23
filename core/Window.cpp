#include "Window.h"

void Window::Init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tieto Praxe - Game");
    SetTargetFPS(60);
    player = Player();
    player.Init();
    inputManager = InputManager();
    inputManager.Init();
    renderer = Renderer();
    Update();
}


void Window::Update() {
    while(!WindowShouldClose()) {
        inputManager.Update(player);
        BeginDrawing();
        player.Update();
        renderer.Render(player);
        ClearBackground(BLACK);
        DrawText(TextFormat("Player health: %d", player.GetHealth()),20, 10, 20, RED);
        DrawText(TextFormat("Score: %d", player.GetScore()), SCREEN_WIDTH / 2, 10,20, WHITE);
        EndDrawing();
    }
    CloseWindow();
    player.UnloadPlayerTexture();
}