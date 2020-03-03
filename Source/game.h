#pragma once
#include "character.h"
class Game
{
    public:
        Game();
        void CreateCharacter();
        static void ClearScreen();
        void ChooseRace();
        void ChooseRole();
        void ShowStats();
        void updateStats();
        void outofcombatCalc();
        //void ShowRace(int index);
        Character* character;
        bool inBattle;
        bool running;
    private:
        unsigned long turnCount;
};