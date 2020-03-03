#pragma once

class Game
{
    public:
        Game();
        void CreateCharacter();
        bool inBattle;
    private:
        unsigned long turnCount;
};