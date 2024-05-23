#include "GameScene.h"

void GameScene::Init() {
    SetScene(GameScene::SCENE_MENU);
}

GameScene::Scene GameScene::GetCurrentScene() const {
    return this->currentScene;
}

void GameScene::SetScene(GameScene::Scene scene) {
    this->currentScene = scene;
}