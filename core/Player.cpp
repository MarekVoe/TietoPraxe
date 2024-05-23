#include "Player.h"


void Player::Init() {
    playerDebugModel.x = 20;
    playerDebugModel.y = 20;
    playerDebugModel.width = 20;
    playerDebugModel.height = 20;
    speed.x = 5;
    speed.y = 5;
    color = WHITE;
}

void Player::Update() {

}

Rectangle& Player::GetPlayerModel() {
    return this->playerDebugModel;
}

Vector2 Player::GetPlayerSpeed() {
    return this->speed;
}

Color Player::GetColor() {
    return this->color;
}