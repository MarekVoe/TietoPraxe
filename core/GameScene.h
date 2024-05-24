#pragma once

class GameScene {
public:
    enum Scene {
        SCENE_MAIN,
        SCENE_MENU,
        SCENE_GAME_OVER
    };
    Scene GetCurrentScene() const;
    void SetScene(Scene scene);
    void Init();
private:
    Scene currentScene;
};