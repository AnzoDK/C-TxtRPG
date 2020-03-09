#pragma once
#include "character.h"
#include "dungeon.h"
class Game
{
    public:
        static std::string nextDirection;
        Game();
        void CreateCharacter();
        static void ClearScreen();
        void ChooseRace();
        void ChooseRole();
        void ShowStats();
        void updateStats();
        void outofcombatCalc();
        void processTurn();
        //void ShowRace(int index);
        Character* character;
        bool inBattle;
        bool running;
        Dungeon currDungeon;
        void ProcessMove();
    private:
        unsigned long turnCount;
        std::string GetInput();
        void Validate(std::string input);
};