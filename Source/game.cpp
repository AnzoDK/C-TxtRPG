#include <iostream>
#include "game.h"
#include "character.h"
using namespace std;

Game::Game()
{
    inBattle = false;
    cout << "Welcome to CTXTRPG" << endl;
}
void Game::CreateCharacter()
{
    Character* c = new Character();
    Stats s;
    cout << "Let's start - Rolling stats for you ;)" << endl;
    s.RollStats();
    c->characterStats = s;
    cout << "Your stats are: " << endl;
    c->characterStats.PrintStats();
}
