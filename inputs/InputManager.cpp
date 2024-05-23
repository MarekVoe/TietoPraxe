#include "InputManager.h"
#include "../core/Player.h"


void InputManager::Init() {

}

void InputManager::Update(Player& player) {
    if (IsKeyDown(KEY_D)) player.GetPlayerModel().x += player.GetPlayerSpeed().x;
    if (IsKeyDown(KEY_A)) player.GetPlayerModel().x -= player.GetPlayerSpeed().x;
    if (IsKeyDown(KEY_W)) player.GetPlayerModel().y -= player.GetPlayerSpeed().y;
    if (IsKeyDown(KEY_S)) player.GetPlayerModel().y += player.GetPlayerSpeed().y;
}