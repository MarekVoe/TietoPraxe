#include "Player.h"

void Player::Init() {
    shipTexture = LoadTexture("../assets/ShipSprite.png");
    playerDebugModel = { 0.0f, 0.0f, (float)shipTexture.width, (float)shipTexture.height };
    position = {1280 / 2, 720 / 2};
    speed.x = 5;
    speed.y = 5;
    color = WHITE;
    score = 0;

    for (int i = 0; i < NUM_SHOOTS; i++) {
        shootModels[i] = { 0.0f, 0.0f, 10.0f, 5.0f };
        shootSpeed = { 7.0f, 0.0f };
        shootActive[i] = false;
    }
}

void Player::Shoot() {
        shootRate += 5;
        for (int i = 0; i < NUM_SHOOTS; i++) {
            if (!shootActive[i] && shootRate % 20 == 0) {
                shootActive[i] = true;
                shootModels[i].x = position.x;
                shootModels[i].y = position.y + playerDebugModel.height / 4;
                ammo--;
                break;
            }
        }
}

void Player::Update(GameScene& gameScene) {
    if (position.x <= 0) position.x = 0;
    if (position.x + playerDebugModel.width >= 1280) position.x = 1280 - playerDebugModel.width;
    if (position.y <= 0) position.y = 0;
    if (position.y + playerDebugModel.height >= 720) position.y = 720 - playerDebugModel.height;

    if (health <= 0) {
        gameScene.SetScene(GameScene::SCENE_GAME_OVER);
    }

    for (int i = 0; i < NUM_SHOOTS; i++) {
        if (shootActive[i]) {
            shootModels[i].x += shootSpeed.x;
            shootModels[i].y += shootSpeed.y;

            if (shootModels[i].x + shootModels[i].width >= GetScreenWidth()) {
                shootActive[i] = false;
            }
        }
    }
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

int Player::GetAmmo() {
    return this->ammo;
}

void Player::SetAmmo(int ammo) {
    this->ammo = ammo;
}