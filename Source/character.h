#pragma once

#include <iostream>
#include <vector>
struct Stats
{
    int Int,Dex,Str,Mem,Cha,Per,Luc;
    void RollStats();
    void PrintStats();
};

class Role
{
    public:
        std::string name;
        Stats RoleStats;  
    private:
        

};
class Race
{
    public:
        std::string name;
        Stats RaceStats;
};

class StatManager
{
    public:
        StatManager();
        std::vector<Stats> *roleStats;
        std::vector<std::string> *roleNames;
        std::vector<Stats> *raceStats;
        std::vector<std::string> *raceNames;
        Role SelectRole(int index);
        Race SelectRace(int index);
        void PrintRaceStats(int index);
        void PrintRoleStats(int index);
        
};

class Character
{
    public:
        std::string name;
        Role characterRole;
        Race characterRace;
        Stats characterStats;
        Stats currentStats;
        Stats bonusStats;
        //void CreateCharacter();
    private:
        Stats m_bonusStats;
};
