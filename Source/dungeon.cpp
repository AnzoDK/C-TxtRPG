#include "dungeon.h"
#include <algorithm>
#include <random>
RoomConnector::RoomConnector()
{
    right = 0;
    left = 0;
    forward = 0;
    backwards = 0;
}

Room::Room(RoomType T)
{
    rt = T;
    rc = RoomConnector();
}
RoomType Room::getRoomType()
{
    return rt;
}

void Dungeon::GenerateLayout(int entryID,int exitID,Floor f,std::default_random_engine rng)
{
    int seed = rand() % 10000 + 1;
    rng.seed = seed;
    std::shuffle(std::begin(f.floorRooms),std::end(f.floorRooms),rng);
    for(int i = 0; i < f.floorRooms.size();i++)
    {
        Room nextRoom = f.floorRooms.at(i+1);
        Room currRoom = f.floorRooms.at(i);
        if(f.floorRooms.at(i).getRoomType() == RoomType(0))
        {
            //if(f.floorRooms.at(i).rc.)
            f.floorRooms.at(i).rc.forward = f.floorRooms.at(i+1).id;
            switch(f.floorRooms.at(i+1).getRoomType )
            {
                case RoomType::normal:
                    f.floorRooms.at(i+1).rc.backwards = f.floorRooms.at(i).id;
                break;

                case RoomType::Troom:
                    nextRoom.rc.backwards = currRoom.id;
                break;

                case RoomType::crossRoom:
                    nextRoom.rc.backwards = currRoom.id;
                break;

                case RoomType::entry:
                    nextRoom.rc.forward = currRoom.id;
                break;

                default:
                    nextRoom.rc.backwards = currRoom.id;
                break;

            }
        }
        else if(f.floorRooms.at(i).getRoomType() == RoomType(1))
        {
            switch(nextRoom.getRoomType)
            {
                default:
                    if((rand() % 2 + 1) > 1)
                    {
                        nextRoom.rc.backwards = currRoom.id;
                        currRoom.rc.right = nextRoom.id;
                        if(f.floorRooms.at(i+2).getRoomType == RoomType::entry)
                        {
                            f.floorRooms.at(i+2).rc.forward = currRoom.id;
                        }
                        else
                        {
                            f.floorRooms.at(i+2).rc.backwards = currRoom.id;    
                        }

                        currRoom.rc.left = f.floorRooms.at(i+2).id;
                    }
                    else
                    {
                        nextRoom.rc.backwards = currRoom.id;
                        currRoom.rc.left = nextRoom.id;
                        if(f.floorRooms.at(i+2).getRoomType == RoomType::entry)
                        {
                            f.floorRooms.at(i+2).rc.forward = currRoom.id;
                        }
                        else
                        {
                            f.floorRooms.at(i+2).rc.backwards = currRoom.id;    
                        }
                        
                        currRoom.rc.right = f.floorRooms.at(i+2).id;
                    }
                break;
            }
        }
        else if(f.floorRooms.at(i).getRoomType() == RoomType(2))
        {

            switch(nextRoom.getRoomType)
            {
                default:
                    if((rand() % 2 + 1) > 1)
                    {
                        nextRoom.rc.backwards = currRoom.id;
                        currRoom.rc.right = nextRoom.id;
                        if(f.floorRooms.at(i+2).getRoomType == RoomType::entry)
                        {
                            f.floorRooms.at(i+2).rc.forward = currRoom.id;
                        }
                        else
                        {
                            f.floorRooms.at(i+2).rc.backwards = currRoom.id;    
                        }

                        currRoom.rc.left = f.floorRooms.at(i+2).id;
                    }
                    else
                    {
                        nextRoom.rc.backwards = currRoom.id;
                        currRoom.rc.left = nextRoom.id;
                        if(f.floorRooms.at(i+2).getRoomType == RoomType::entry)
                        {
                            f.floorRooms.at(i+2).rc.forward = currRoom.id;
                        }
                        else
                        {
                            f.floorRooms.at(i+2).rc.backwards = currRoom.id;    
                        }
                        
                        currRoom.rc.right = f.floorRooms.at(i+2).id;
                    }
                    if(f.floorRooms.at(i+3).getRoomType == RoomType::entry)
                        {
                            f.floorRooms.at(i+3).rc.forward = currRoom.id;
                        }
                        else
                        {
                            f.floorRooms.at(i+3).rc.backwards = currRoom.id;    
                        }
                break;
            }

        }
        else if(f.floorRooms.at(i).getRoomType() == RoomType(3))
        {

        }
        else
        {
            
        }
        
        
    }

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
    auto rng = std::default_random_engine {};
    floors = std::vector<Floor>();
    long floorCount = rand() %10000 +1;
    for (int i = 0; i < floorCount; i++)
    {
        GenerateRooms();
        GenerateLayout(0,floors.at(i).floorRooms.size()-1,floors.at(i),rng);
    }
}