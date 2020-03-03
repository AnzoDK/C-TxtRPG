#include <iostream>
#include "game.h"
int main()
{
    Game* g = new Game();
    g->CreateCharacter();
    while(g->running)
    {
        g->updateStats();
        g->outofcombatCalc();
    }
    return 0;
}