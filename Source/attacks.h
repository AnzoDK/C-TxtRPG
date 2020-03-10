#pragma once
#include "enemies.h"

class Slash : public AttackBase
{
    public:
        Slash();
        void OnHit() override;
};

class FrostBlast : public AttackBase
{
    public:
        FrostBlast();
        void OnHit() override;
};