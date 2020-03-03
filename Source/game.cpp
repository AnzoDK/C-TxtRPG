#include <iostream>
#include <cstdlib>
#include "game.h"
using namespace std;
void Game::ClearScreen()
{
    
    int n;
    for (n = 0; n < 10; n++)
    printf( "\n\n\n\n\n\n\n\n\n\n" );
    
}
Game::Game()
{
    inBattle = false;
    running = false;
    cout << "Welcome to CTXTRPG" << endl;
}
void Game::ChooseRace()
{
    StatManager* man = new StatManager();
    cout << "Now now - We also need to find out what your race is!" << endl;
    for(int i = 0; i < man->raceNames->size();i++)
    {
        cout << i+1 << man->raceNames->at(i) << endl;
    }
    cout << ">";
    string s;
    cin >> s;

    int input = 0;
    input = atoi(s.c_str());
    input--;
    if(input > man->raceNames->size()-1)
    {
        cout << "invalid input... Press 'Enter' to retry!" << endl;
        cin;
        ChooseRace();
    }
    else
    {
        Game::ClearScreen();
        man->PrintRaceStats(input);
        cout << "Press 'Enter' to accept these stats or 'x' to return" << endl;
        char c;
        cin >> c;
        if(c == 'x')
        {
            ChooseRace();
        }
        else
        {
            Race r;
            r.name = man->raceNames->at(input);
            r.RaceStats = man->raceStats->at(input);
            character->characterRace = r;
        }
        
    }
    delete(man);
    
}
void Game::ChooseRole()
{
    StatManager* man = new StatManager();
    for(int i = 0; i < man->roleNames->size();i++)
    {
        cout << i+1 << man->roleNames->at(i) << endl;
    }
    cout << ">";
    string s;
    cin >> s;

    int input = 0;
    input = atoi(s.c_str());
    input--;
    if(input > man->roleNames->size()-1)
    {
        cout << "invalid input... Press 'Enter' to retry!" << endl;
        cin;
        ChooseRole();
    }
    else
    {
        Game::ClearScreen();
        man->PrintRoleStats(input);
        cout << "Press 'Enter' to accept these stats or 'x' to return" << endl;
        char c;
        cin >> c;
        if(c == 'x')
        {
            ChooseRole();
        }
        else
        {
            Role r;
            r.name = man->roleNames->at(input);
            r.RoleStats = man->roleStats->at(input);
            character->characterRole = r;
        }
        
    }
    delete(man);
    
}
void Game::updateStats()
{
    Stats s;
    s.Cha = character->characterStats.Cha + character->characterRace.RaceStats.Cha + character->characterRole.RoleStats.Cha;
    s.Dex = character->characterStats.Dex + character->characterRace.RaceStats.Dex + character->characterRole.RoleStats.Dex;
    s.Int = character->characterStats.Int + character->characterRace.RaceStats.Int + character->characterRole.RoleStats.Int;
    s.Str = character->characterStats.Str + character->characterRace.RaceStats.Str + character->characterRole.RoleStats.Str;
    s.Mem = character->characterStats.Mem + character->characterRace.RaceStats.Mem + character->characterRole.RoleStats.Mem;
    s.Per = character->characterStats.Per + character->characterRace.RaceStats.Per + character->characterRole.RoleStats.Per;
    s.Luc = character->characterStats.Luc + character->characterRace.RaceStats.Luc + character->characterRole.RoleStats.Luc;
    character->currentStats = s;
}
void Game::ShowStats()
{
    updateStats();
    cout << "Your current stats are: " << endl;
    std::cout 
    << "Intelligence: " << character->currentStats.Int << std::endl 
    << "Dexterity: " << character->currentStats.Dex << std::endl << "Strength: " << std::endl 
    << "Memory: " << character->currentStats.Mem << std::endl 
    << "Charisma: " << character->currentStats.Cha << std::endl 
    << "Perception: " << character->currentStats.Per << std::endl 
    << "Luck: " << character->currentStats.Luc << std::endl;

}
void Game::CreateCharacter()
{
    character = new Character();
    Stats s;
    cout << "Let's get started by giving you a name..." << endl << "Who are you?" << endl;
    getline(cin,character->name);
    cout << "Cheers " << character->name << "I'm going to roll some stats for you ;)" << endl;
    s.RollStats();
    character->characterStats = s;
    cout << "Your stats are: " << endl;
    character->characterStats.PrintStats();
    cout << "To continue press 'Enter'" << endl;
    cin;
    Game::ClearScreen();
    ChooseRace();
    Game::ClearScreen();
    cout << "You chose: " << character->characterRace.name << " not a bad choice ;)" << endl;
    cout << "Now choose your profession..." << endl;
    ChooseRole();
    Game::ClearScreen();
    cout << "You are now ready - Lets take a final look at your stats!" << endl;

}
void Game::outofcombatCalc()
{

}

