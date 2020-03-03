#include "character.h"
#include "dice.h"
void Stats::RollStats()
{
    
    srand((unsigned) time(0));
    Int = static_cast<int>(Dice::iRoll(20));
    Dex = static_cast<int>(Dice::iRoll(20));
    Str = static_cast<int>(Dice::iRoll(20));
    Mem = static_cast<int>(Dice::iRoll(20));
    Cha = static_cast<int>(Dice::iRoll(20));
    Per = static_cast<int>(Dice::iRoll(20));
    Luc = static_cast<int>(Dice::iRoll(10));
}
void Stats::PrintStats()
{
    std::cout 
    << "Intelligence: " << Int << std::endl 
    << "Dexterity: " << Dex << std::endl << "Strength: " << std::endl 
    << "Memory: " << Mem << std::endl 
    << "Charisma: " << Cha << std::endl 
    << "Perception: " << Per << std::endl 
    << "Luck: " << Luc << std::endl;
}
StatManager::StatManager()
{
    roleNames = new std::vector<std::string>();
    roleStats = new std::vector<Stats>();
    raceNames = new std::vector<std::string>();
    raceStats = new std::vector<Stats>();
    //Roles
    roleNames->push_back("Researcher");
    Stats researcher;
    researcher.Cha = 0;
    researcher.Int = 3;
    researcher.Dex = -1;
    researcher.Str = -2;
    researcher.Mem = 4;
    researcher.Per = 3;
    researcher.Luc = 2;
    roleStats->push_back(researcher);
    //Races
    raceNames->push_back("Human");
    Stats human;
    human.Cha = 1;
    human.Int = -2;
    human.Dex = 2;
    human.Str = 1;
    human.Mem = -2;
    human.Per = -1;
    human.Luc = 1;
    raceStats->push_back(human);


}
Role StatManager::SelectRole(int index)
{
    Role role;
    int max = roleNames->size();
    max--;

    if(index > max)
    {
        //Error out - index too high
    }
    else
    {
        role.name = roleNames->at(index);
        role.RoleStats = roleStats->at(index);

    }
    return role;   
}
Race StatManager::SelectRace(int index)
{
    Race race;
    int max = raceNames->size();
    max--;

    if(index > max)
    {
        //Error out - index too high
    }
    else
    {
        race.name = raceNames->at(index);
        race.RaceStats = raceStats->at(index);

    }
    return race;   
}
void StatManager::PrintRaceStats(int index)
{
    std::cout << "This race has the following bonus stats..." << std::endl;
    std::cout 
    << "Intelligence: " << raceStats->at(index).Int << std::endl 
    << "Dexterity: " << raceStats->at(index).Dex << std::endl << "Strength: " << std::endl 
    << "Memory: " << raceStats->at(index).Mem << std::endl 
    << "Charisma: " << raceStats->at(index).Cha << std::endl 
    << "Perception: " << raceStats->at(index).Per << std::endl 
    << "Luck: " << raceStats->at(index).Luc << std::endl;
}
void StatManager::PrintRoleStats(int index)
{
    std::cout << "This role has the following bonus stats..." << std::endl;
    std::cout 
    << "Intelligence: " << roleStats->at(index).Int << std::endl 
    << "Dexterity: " << roleStats->at(index).Dex << std::endl << "Strength: " << std::endl 
    << "Memory: " << roleStats->at(index).Mem << std::endl 
    << "Charisma: " << roleStats->at(index).Cha << std::endl 
    << "Perception: " << roleStats->at(index).Per << std::endl 
    << "Luck: " << roleStats->at(index).Luc << std::endl;
}
