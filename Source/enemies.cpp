#include "enemies.h"
#include "attacks.h"
AttackBase::AttackBase()
{
    name = "";
    dmg = 0;
    dType = DamageType::none;
    manaCost = 0;
}

void AttackBase::OnHit()
{
    //This is reserved for overriding
}

void EnemyBase::OnBattleStart()
{

}

EnemyBase::EnemyBase()
{
    level = 0;
    eStats = Stats();
    name = "";
    weakness = DamageType::none;
}

void Skeleton::Init()
{
    weakness = DamageType::fire;
    attacks = std::vector<AttackBase>();
    eStats.Dex = 0.5 * level;
    eStats.Int = 0.2 * level;
    eStats.Str = 1.5 * level;
    FrostBlast atk1 = FrostBlast();
    Slash atk2 = Slash();


    atk1.dmg = 0.5 * eStats.Int;
    atk1.manaCost = level * 1.7 - (eStats.Int/3);
    atk2.dmg = 1 * eStats.Str;
    atk1.manaCost = 0;

    attacks.push_back(atk1);
    attacks.push_back(atk2);
    

}

void Skeleton::OnBattleStart()
{
    std::cout << "The sound of rattleing bones can be heard in the distance..." << std::endl;
    std::cout << "Your strength falls by 1 out of fear" << std::endl;
}

Skeleton::Skeleton()
{
    level = 1;
    Init();
}

Skeleton::Skeleton(int lvl)
{
    level = lvl;
    Init();
}