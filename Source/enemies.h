#pragma once
#include <iostream>
#include "character.h"

enum DamageType{none,fire,ice,pure};

class AttackBase
{
    public:
        AttackBase();
        int dmg;
        virtual void OnHit();
        std::string name;
        DamageType dType;
        int manaCost;
    private:
};

class EnemyBase : public EntityBase
{
    public:
        EnemyBase();
        virtual void OnBattleStart();
        int level;
        Stats eStats;
        std::string name;
        DamageType weakness;
        std::vector<AttackBase> attacks;
};

class Skeleton : public EnemyBase
{
    public:
        Skeleton();
        Skeleton(int lvl);
        void Init();
        virtual void OnBattleStart() override;
};