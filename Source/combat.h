#pragma once
#include "enemies.h"

class CombatManager
{
    public:
        void ProcessCombat();
        std::vector<EntityBase> combatEntities;
};