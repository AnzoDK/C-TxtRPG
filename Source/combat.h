#pragma once
#include "enemies.h"

class CombatManager
{
    public:
        void ProcessCombat();
        void NewCombat(std::vector<EnemyBase> units);
        std::vector<EnemyBase> enemies;
        std::vector<EntityBase> combatEntities;
};