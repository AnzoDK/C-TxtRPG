#include "roomConnector.h"

RoomConnector::RoomConnector()
{
    /*
    right = -1;
    left = -1;
    forward = -1;
    backwards = -1;
    */
   r_right = new Room();
   r_left = new Room();
   r_forward = new Room();
   r_backwards = new Room();
}