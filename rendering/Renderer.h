#pragma once

#include "../core/Player.h"
#include "../core/GameScene.h"

class Renderer {
public:
    void Init();
    void RenderGame(Player player);
    void RenderMenu(GameScene& gameScene);
    void RenderGameOver(GameScene& gameScene);
private:
    Texture2D backgroundTexture;
};