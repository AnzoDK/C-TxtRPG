#include "combat.h"

void CombatManager::NewCombat(std::vector<EnemyBase> units)
{
    enemies = units;

    std::vector<EnemyBase> turns = std::vector<EnemyBase>();

    while(units.size() > 0)
    {
        EnemyBase top = EnemyBase();
        int topIndex;
        for(unsigned int i = 0; i < units.size();i++)
        {
            if(units.at(i).eStats.Dex > top.eStats.Dex)
            {
                top = units.at(i);
            }
        }
        turns.push_back(top);
        enemies.erase(enemies.begin()+topIndex);
    }
}

CombatManager::CombatManager()
{
    combatEntities = std::vector<EntityBase>();
}

void CombatManager::ProcessCombat()
{

}