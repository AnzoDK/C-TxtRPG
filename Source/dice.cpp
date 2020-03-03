#include "dice.h"
#include <cstdlib>
#include <time.h>
int Dice::iRoll(int size)
{
    return std::rand()% size + 1;
}
double Dice::dRoll(int size)
{
    
}