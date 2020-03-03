#include <iostream>
int doubleToIntConvert(double d)
{
std::cout << d << std::endl;
int i = static_cast<int>(d); //Kan også konverteres via en forældet metode med: int i = (int)d;
std::cout << i << std::endl;
return i;
}

int main()
{
int i = doubleToIntConvert(3.212);


}


/*
Prefixes for Types in C++

Class C
bool b
char c
double d
long l
long pointer lp
integer n (or) i
membervariables m_
pointer p
string s
null-terminated string sz
array arr

ALL VARIABLED MUST BE INITILIZED BEFORE USE OR THEY CAN BE UNPREDICTABLE
*/
