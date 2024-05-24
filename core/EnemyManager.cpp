#include <iostream>
#include "EnemyManager.h"

void EnemyManager::Init(int maxEnemies) {
    this->maxEnemies = maxEnemies;
    enemies.reserve(maxEnemies);
}

void EnemyManager::Update(Player &player) {
    for (auto& enemy : enemies) {
        if (enemy.IsActive()) {
            enemy.Update(player);
        }
    }
}

void EnemyManager::Draw() {
    for (auto& enemy: enemies) {
        if (enemy.IsActive()) {
            enemy.Draw();
        }
    }
}

void EnemyManager::SpawnEnemy(Vector2 startPos, Vector2 startSpeed, Color color) {
    bool spawned = false;

    // Pokud je místo pro nového nepřítele, vytvoříme ho a přidáme do vektoru
    if (enemies.size() < maxEnemies) {
        Enemy enemy;
        enemy.Init(startPos, startSpeed, color);
        enemies.push_back(enemy);
        spawned = true;
    } else {
        for (auto& enemy : enemies) {
            if (!enemy.IsActive()) {
                enemy.Init(startPos, startSpeed, color);
                spawned = true;
                break;
            }
        }
    }

    if (spawned) {
        std::cout << "Enemy Spawned" << std::endl;
    }
}

