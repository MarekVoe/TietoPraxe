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
        EndDrawing();
    }
    CloseWindow();
}