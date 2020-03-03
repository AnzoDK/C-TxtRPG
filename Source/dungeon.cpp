#include "dungeon.h"

Room::Room(RoomType T)
{
    rt = T;
}


void Dungeon::GenerateLayout()
{

}

void Dungeon::GenerateRooms()
{
    std::vector<Room> rooms = std::vector<Room>();
    Room entryRoom = Room(static_cast<RoomType>(4));
    rooms.push_back(entryRoom);
    long roomCount = rand() %10000 +1;
    std::cout << "Generating " << roomCount << " Rooms - Hold on!" << std::endl;
    std::vector<long>Trooms = std::vector<long>();
    std::vector<long>crossRooms = std::vector<long>();
    for(int i = 0;i < roomCount;i++)
    {
        Room room;
        int type = rand() %2;
        room = Room(static_cast<RoomType>(type));
        room.id = i;
        if(type == 1)
        {
            Trooms.push_back(room.id);
        }
        else if (type == 2)
        {
            crossRooms.push_back(room.id);
        }
        rooms.push_back(room);

    }
    Room exitRoom = Room(static_cast<RoomType>(5));
    rooms.push_back(exitRoom);
}