#include "Enemy.h"

void Enemy::Init(Vector2 startPos, Vector2 startSpeed, Color color) {
    enemyModel = {startPos.x, startPos.y, 32,32};
    speed = startSpeed;
    this->color = color;
    active = true;
    enemyTexture = LoadTexture("../assets/EnemySprite.png");

    for (int i = 0; i < NUM_SHOOTS; i++) {
        shootModels[i] = {0.0f, 0.0f, 10.0f, 5.0f};
        shootSpeed = {-5.0f, 0.0f};
        shootActive[i] = false;
    }
}

void Enemy::Update(Player &player) {
    if (!active)
        return;

    enemyModel.x += speed.x;

    if (enemyModel.x + enemyModel.width < 0) {
        active = false;
    }

    Enemy::Shoot(player);

    for (int i = 0; i < NUM_SHOOTS; i++) {
        if (shootActive[i]) {
            shootModels[i].x += shootSpeed.x;

            if (shootModels[i].x + shootModels[i].width < 0) {
                shootActive[i] = false;
            }
            if (CheckCollisionRecs(shootModels[i], player.GetPlayerModel())) {
                shootActive[i] = false;
                player.SetHealth(player.GetHealth() - 1);
            }
        }
    }
}

void Enemy::Shoot(Player &player) {
    shootRate += 5;
    for (int i = 0; i < NUM_SHOOTS; i++) {
        if (!shootActive[i] && shootRate % 100 == 0) {
            shootActive[i] = true;
            shootModels[i].x = enemyModel.x;
            shootModels[i].y = enemyModel.y + enemyModel.height / 4;
            break;
        }
    }
}

void Enemy::Draw() {
    if (active) {
        Rectangle sourceRect = {0.0f, 0.0f, (float)enemyTexture.width, (float)enemyTexture.height};
        Vector2 position = {enemyModel.x, enemyModel.y};
        DrawTextureRec(enemyTexture, sourceRect, position, color);

        for (int i = 0; i < NUM_SHOOTS; i++) {
            if (shootActive[i]) {
                DrawRectangleRec(shootModels[i], RED);
            }
        }
    }
}

bool Enemy::IsActive() {
    return active;
}