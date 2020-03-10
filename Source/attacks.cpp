#include "attacks.h"
#include "dice.h"


Slash::Slash()
{
    dType = DamageType::none;
    dmg = 0;
}
void Slash::OnHit()
{
    //Nothing really
}


FrostBlast::FrostBlast()
{
    dmg = 0;
    dType = DamageType::ice;
}

void FrostBlast::OnHit()
{
    std::cout << "You are freezing..." << std::endl;
    std::cout << "Rolling dice..." << std::endl;
    int roll = Dice::iRoll(20);
    if(roll > 5)
    {
        std::cout << "You rolled " << roll << std::endl;
        std::cout << "The freezing feeling has left your body" << std::endl;
    }
    else
    {
        std::cout << "You rolled " << roll << std::endl;
        std::cout << "You feel your hear turn to ice - You are now frozen" << std::endl;
    }
    
}