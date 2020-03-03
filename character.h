#pragma once

#include <iostream>
#include <vector>
struct Stats
{
    int Int,Dex,Str,Mem,Cha,Per,Luc;
    void RollStats();
};

class Role
{
    public:
        Role();
        std::string name;
        Stats RoleStats;   
        void SelectRole(int index);  
    private:
        std::vector<Stats> *roleStats;
        std::vector<std::string> *roleNames;     

};
class Race
{
    public:
        std::string name;
        Stats RaceStats;
};

class Character
{
    public:
        std::string name;
        Role characterRole;
        Race characterRace;
        Stats characterStats;
        void CreateCharacter();
    private:
        Stats m_bonusStats;
};
