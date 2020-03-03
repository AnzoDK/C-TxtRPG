#include "character.h"
#include "dice.h"
void Stats::RollStats()
{
    
    
    Int = static_cast<int>(Dice::iRoll(20));
    Dex = static_cast<int>(Dice::iRoll(20));
    Str = static_cast<int>(Dice::iRoll(20));
    Mem = static_cast<int>(Dice::iRoll(20));
    Cha = static_cast<int>(Dice::iRoll(20));
    Luc = static_cast<int>(Dice::iRoll(10));
}
Role::Role()
{
    roleNames = new std::vector<std::string>();
    roleStats = new std::vector<Stats>();
    roleNames->push_back("Researcher");
    Stats researcher;
    researcher.Cha = 0;
    researcher.Int = 3;
    researcher.Dex = -1;
    researcher.Str = -2;
    researcher.Mem = 4;
    researcher.Per = 3;
    roleStats->push_back(researcher);

}
void Role::SelectRole(int index)
{
    int max = roleNames->size();
    max--;

    if(index > max)
    {
        //Error out - index too high
    }
    else
    {
        name = roleNames->at(index);
        RoleStats = roleStats->at(index);

    }
    
}