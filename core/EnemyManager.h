#pragma once

#include <vector>
#include "Base.h"
#include "Player.h"
#include "Enemy.h"

class EnemyManager {
public:
    void Init(int maxEnemies);
    void Update(Player& player);
    void Draw();
    void SpawnEnemy(Vector2 startPos, Vector2 startSpeed, Color color);
private:
    std::vector<Enemy> enemies;
    int maxEnemies;
};