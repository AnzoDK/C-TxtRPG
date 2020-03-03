#pragma once

#include <iostream>
#include <vector>
class Chest : GameObject
{
    void interacted() override
    {

    }
};

class GameObject
{
    virtual void interacted();

};