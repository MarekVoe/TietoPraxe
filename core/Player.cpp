#include "Player.h"


void Player::Init() {
    shipTexture = LoadTexture("../assets/ShipSprite.png");
    playerDebugModel = { 0.0f, 0.0f, (float)shipTexture.width, (float)shipTexture.height };
    position = {1280 / 2, 720 / 2};
    speed.x = 5;
    speed.y = 5;
    color = WHITE;
    score = 0;
}

void Player::Update() {
    if (position.x <= 0) position.x = 0;
    if (position.x + playerDebugModel.width >= 1280) position.x = 1280 - playerDebugModel.width;
    if (position.y <= 0) position.y = 0;
    if (position.y + playerDebugModel.height >= 720) position.y = 720 - playerDebugModel.height;
}

void Player::SetScore(int score) {
    this->score = score;
}

int Player::GetScore() {
    return this->score;
}

Vector2& Player::GetPlayerPosition() {
    return this->position;
}

void Player::UnloadPlayerTexture() {
    UnloadTexture(shipTexture);
}

Rectangle& Player::GetPlayerModel() {
    return this->playerDebugModel;
}

Vector2 Player::GetPlayerSpeed() {
    return this->speed;
}

Texture2D Player::GetTexture() {
    return this->shipTexture;
}

Color Player::GetColor() {
    return this->color;
}

void Player::SetHealth(int health) {
    this->health = health;
}

int Player::GetHealth() {
    return this->health;
}