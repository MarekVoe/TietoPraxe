#include "InputManager.h"
#include "../core/Player.h"


void InputManager::Init() {

}

void InputManager::Update(Player& player) {
    if (IsKeyDown(KEY_D)) player.GetPlayerPosition().x += player.GetPlayerSpeed().x;
    if (IsKeyDown(KEY_A)) player.GetPlayerPosition().x -= player.GetPlayerSpeed().x;
    if (IsKeyDown(KEY_W)) player.GetPlayerPosition().y -= player.GetPlayerSpeed().y;
    if (IsKeyDown(KEY_S)) player.GetPlayerPosition().y += player.GetPlayerSpeed().y;


    if (IsKeyDown(KEY_SPACE)) {
        player.Shoot();
    }
}
