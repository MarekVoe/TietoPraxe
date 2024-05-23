#pragma once

class GameScene {
public:
    enum Scene {
        SCENE_MAIN,
        SCENE_MENU
    };
    Scene GetCurrentScene() const;
    void SetScene(Scene scene);
    void Init();
private:
    Scene currentScene;
};