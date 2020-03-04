#include "dungeon.h"

Room::Room(RoomType T)
{
    rt = T;
}


void Dungeon::GenerateLayout(Floor f)
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
    Floor f = Floor();
    f.floorRooms = rooms;
    floors.push_back(f);
}
void Dungeon::GenerateFloors()
{
    floors = std::vector<Floor>();
    long floorCount = rand() %10000 +1;
    for (int i = 0; i < floorCount; i++)
    {
        GenerateRooms();
        GenerateLayout(floors.at(i));
    }
}