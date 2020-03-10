#pragma once
#include "dungeon.h"
class Room;

class RoomConnector
{
    public:
        RoomConnector();
        //int right;
        //int left;
        //int forward;
        //int backwards;
        Room* r_right; 
		//= Room();
        Room* r_left; 
		//= Room();
        Room* r_forward; 
		//= Room();
        Room* r_backwards; 
		// = Room();
        //long comesFrom;
};