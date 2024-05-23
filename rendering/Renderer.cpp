#include "Renderer.h"
#include "../core/Window.h"

void Renderer::RenderGame(Player player) {
    DrawTextureRec(player.GetTexture(), player.GetPlayerModel(), player.GetPlayerPosition(), player.GetColor());
    DrawText(TextFormat("Player health: %d", player.GetHealth()),20, 10, 20, RED);
    DrawText(TextFormat("Player ammo: %d", player.GetAmmo()),20, 40, 20, WHITE);
    DrawText(TextFormat("Score: %d", player.GetScore()), SCREEN_WIDTH / 2, 10,20, WHITE);

    for (int i = 0; i < player.GetNumShoots(); i++) {
        if (player.GetShootActive(i)) {
            DrawRectangleRec(player.GetShootModel(i), player.GetColor());
        }
    }
}

void Renderer::RenderMenu(GameScene& gameScene) {
    Rectangle playGameButton = {1280 / 2 - 100, 720 / 2 - 50, 200, 40};
    Rectangle exitGameButton = {1280 / 2 - 100, 720 / 2 + 50, 200, 40};

    DrawRectangleRec(playGameButton, LIGHTGRAY);
    DrawRectangleLinesEx(playGameButton, 2, GRAY);
    DrawText("Play Game", playGameButton.x + playGameButton.width/2 - MeasureText("Play Game", 20)/2, playGameButton.y + 10, 20, BLUE);

    DrawRectangleRec(exitGameButton, LIGHTGRAY);
    DrawRectangleLinesEx(exitGameButton, 2, GRAY);
    DrawText("Exit Game", exitGameButton.x + exitGameButton.width/2 - MeasureText("Exit Game", 20)/2, exitGameButton.y + 10, 20, BLUE);

    if (CheckCollisionPointRec(GetMousePosition(), playGameButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        gameScene.SetScene(GameScene::SCENE_MAIN);
    }

    if (CheckCollisionPointRec(GetMousePosition(), exitGameButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        CloseWindow();
    }
}