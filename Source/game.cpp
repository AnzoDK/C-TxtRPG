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
        cout << i+1 << ". " << man->raceNames->at(i) << endl;
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
        cout << "Press 'y' to accept these stats or 'x' to return" << endl;
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
        cout << i+1 << ". " << man->roleNames->at(i) << endl;
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
        cout << "Press 'y' to accept these stats or 'x' to return" << endl;
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
    //return;
}
void Game::updateStats()
{
    Stats s;
    s.Cha = character->characterStats.Cha + character->characterRace.RaceStats.Cha + character->characterRole.RoleStats.Cha + character->bonusStats.Cha;
    s.Dex = character->characterStats.Dex + character->characterRace.RaceStats.Dex + character->characterRole.RoleStats.Dex + character->bonusStats.Dex;
    s.Int = character->characterStats.Int + character->characterRace.RaceStats.Int + character->characterRole.RoleStats.Int + character->bonusStats.Int;
    s.Str = character->characterStats.Str + character->characterRace.RaceStats.Str + character->characterRole.RoleStats.Str + character->bonusStats.Str;
    s.Mem = character->characterStats.Mem + character->characterRace.RaceStats.Mem + character->characterRole.RoleStats.Mem + character->bonusStats.Mem;
    s.Per = character->characterStats.Per + character->characterRace.RaceStats.Per + character->characterRole.RoleStats.Per + character->bonusStats.Per;
    s.Luc = character->characterStats.Luc + character->characterRace.RaceStats.Luc + character->characterRole.RoleStats.Luc + character->bonusStats.Luc;
    character->currentStats = s;
}
void Game::ShowStats()
{
    updateStats();
    cout << "Your current stats are: " << endl;
    std::cout 
    << "Intelligence: " << character->currentStats.Int << std::endl 
    << "Dexterity: " << character->currentStats.Dex << std::endl 
	<< "Strength: " << character->currentStats.Str << std::endl 
    << "Memory: " << character->currentStats.Mem << std::endl 
    << "Charisma: " << character->currentStats.Cha << std::endl 
    << "Perception: " << character->currentStats.Per << std::endl 
    << "Luck: " << character->currentStats.Luc << std::endl;

}
void Game::CreateCharacter()
{
    character = new Character();
    Stats bs;
    bs.Cha = 0;
    bs.Dex = 0;
    bs.Int = 0;
    bs.Luc = 0;
    bs.Mem = 0;
    bs.Per = 0;
    bs.Str = 0;
    character->bonusStats = bs;
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
	ShowStats();
	cout << "Press 'Enter' to start" << endl;
	string a;
	getline(cin,a);
    running = true;
}
void Game::outofcombatCalc()
{
    if(!inBattle)
    {

    }
}

void Game::Validate(std::string input)
{

if(currDungeon.currentRoom.re.getEventName() == "None")
    {
        if(input.find("forward") != string::npos || input.find("backwards") != string::npos || input.find("right") != string::npos || input.find("left") != string::npos)
        {
            switch(currDungeon.currentRoom.getRoomType())
            {
                case RoomType::normal:
                    if(input.find("forward") != string::npos)
                    {
                        nextDirection = "forward";
                    }
                    else if(input.find("backwards") != string::npos)
                    {
                       nextDirection = "backwards";
                    }
                    else
                    {
                        cout << "Invalid Input..." << endl;
                        GetInput();
                    }
                    
                break;
            }
        }
    }
    else
    {
        if(input.find("forward") != string::npos || input.find("backwards") != string::npos || input.find("right") != string::npos || input.find("left") != string::npos)
        {
            cout << "There is an event going on! Take care of that first!" << endl;
            Validate(input);
        }
        else
        {
            currDungeon.currentRoom.re.useOptions(input, character);
        }
        
    }

}

string Game::GetInput()
{

    string input = "";
    getline(cin,input);
    Validate(input);
    return nextDirection;
    
    
}

void Game::ProcessMove()
{

    if(nextDirection == "forward")
    {
        currDungeon.currentRoom.rc.r_forward = currDungeon.GenerateRoom();
        currDungeon.currentRoom.rc.r_forward.rc.r_backwards = currDungeon.currentRoom;
        currDungeon.currentRoom = currDungeon.currentRoom.rc.r_forward;
    }
    else if(nextDirection == "backwards")
    {
        currDungeon.currentRoom = currDungeon.currentRoom.rc.r_backwards;
        
    }
    else if(nextDirection == "right")
    {
        currDungeon.currentRoom.rc.r_right = currDungeon.GenerateRoom();
        currDungeon.currentRoom.rc.r_right.rc.r_backwards = currDungeon.currentRoom;
        currDungeon.currentRoom = currDungeon.currentRoom.rc.r_right;
    }
    else
    {
        currDungeon.currentRoom.rc.r_left = currDungeon.GenerateRoom();
        currDungeon.currentRoom.rc.r_left.rc.r_backwards = currDungeon.currentRoom;
        currDungeon.currentRoom = currDungeon.currentRoom.rc.r_left;
    }
    currDungeon.currentRoom.OnEnter();
    
    
    
    
}

void Game::processTurn()
{
    if(inBattle)
    {

    }
    else
    {
        //wait for input;
        switch(currDungeon.currentRoom.getRoomType())
        {
            case RoomType::normal:
                cout << "You stand in a hallway - One way forward, one way back..." << endl;
                cout << "[Options: forward, backwards]" << endl;
            break;
            case RoomType::Troom:
                cout << "You met T-Crossing - You are now puzzled with a dilemma... Right? or Left?" << endl;
                cout << "[Options: right, left, backwards]" << endl;
            break;
            case RoomType::crossRoom:
                cout << "You are standing in the middle of a large room. It would seem that you can go in every direction !!" << endl;
                cout << "[Options: forward, right, left, backwards]" << endl;
            break;
            case RoomType::entry:
                cout << "You have entered a new floor... I wonder what horrors, that await you in the darkness..." << endl;
                cout << "[Options: forward]" << endl;
            break;
            break;
            case RoomType::dead_end:
                cout << "You enter a dark room. You let your hand slide along the cold, hard stone walls..." << endl << "To your suprise you realize that there is no way to go... It's a dead end!" << endl;
                cout << "[Options: backwards]" << endl;
            break;
            case RoomType::exit:
                cout << "A well lit room apears before your eyes... The door behind you shuts close, with the force of Thor..." << endl << "You shake in fear, awating your death... But it never comes..." << endl << "Instead, the ground underneath you starts to fall apart... You spot a ladder that goes downwards..." << endl;
                cout << "[Options: exit (floor)]" << endl;
            break;
        }
        if(!currDungeon.currentRoom.re.Event())
        {
            //Success we proccessed the Event correctly
        }
        else
        {
            cout << "An error occoured while trying to proccess the room event..." << endl << "This is a bug... Continueing gameplay anyways..." << endl;
        }
        string direction = GetInput();
        
        
    }
    
}

