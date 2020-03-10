#include "dungeon.h"
#include <algorithm>
#include <random>
#include "dice.h"
#include "game.h"



/*RoomEvent::RoomEvent()
{
    options = "";
    eventName = "None";
    Init();
}*/
void RoomEvent::Init()
{
    //Empty
}

void RoomEvent::PreInit()
{
    options = "";
    eventName = "None";
}

int RoomEvent::Event()
{
    //this is the None-Event...
    //This always return 0 :)
    return 0;
}
void RoomEvent::useOptions(std::string input, Character* c)
{
    //options are not available for the None-Event;
}
std::string RoomEvent::getEventName()
{
    return eventName;
}

void Ambush::Init()
{
    eventName = "Ambush";
    options = "attempt escape, fight";
}
int Ambush::Event()
{
    std::cout << "You got ambushed! - Monsters are closing in on you..." << std::endl << "You got new options! : " << "[" << options << "]" << std::endl;
    return 0;
}
void Ambush::useOptions(std::string input, Character* c)
{
    if(input.find("attempt") != std::string::npos)
    {
        int roll = Dice::iRoll(20);
        if(roll + c->currentStats.Dex > 17)
        {
            //Sucess
            std::cout << "You escaped the monsters!" << std::endl << "You go back a room" << std::endl;
            Game::nextDirection = "backwards";
        }
        else
        {
            //fail

            //Combat!
        }
        
    }
    else if(input.find("fight") != std::string::npos)
    {
        //combat
    }
    else
    {
        //invalid Input
        std::cout << "Invalid Input" << std::endl;
        std::string inp = "";
        getline(std::cin,inp);
        useOptions(inp,c);
    }
    
}


/*Room::Room(RoomType T)
{
    rt = T;
    rc = new RoomConnector();
    re = RoomEvent();
}*/
void Room::init(RoomType T)
{
    rt = T;
    rc = new RoomConnector();
    re = RoomEvent();
}
void Room::OnEnter()
{
    //Normal Room = no output
}
RoomType Room::getRoomType()
{
    return rt;
}

Room* Dungeon::GenerateRoom()
{
    Room* tmpRoom = new Room(static_cast<RoomType>(Dice::iRoll(3)-1));
    if(Dice::iRoll(100) > 70)
    {
        switch(Dice::iRoll(2))
        {
            case 1:
                tmpRoom->re = Ambush();
            break;
            case 2:
                tmpRoom->re = RoomEvent();
            break;
        }
    }
    else
    {
        tmpRoom->re = RoomEvent();
    }
    rooms.push_back(tmpRoom);
    return tmpRoom;
    
}
void Dungeon::DeleteRooms()
{
    for(int i = 0; i < rooms.size();i++)
    {
        delete(rooms.at(i));
    }
}



















/*void Dungeon::GenerateLayout(int entryID,int exitID,Floor f,std::default_random_engine rng)
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
*/


/*int Dungeon::GenerateRoom(std::vector<Room> *rs,int *createCounter)
{
    int counter = int(*createCounter);
    while(counter > 0)
    {
        Room currTmpRoom = Room(static_cast<RoomType>(rand() % 2));
        switch(currTmpRoom.getRoomType())
        {
            case RoomType::normal:

            break;
        }
        counter--;
    }
}
*/
/*void Dungeon::GenerateRooms()
{
    
    std::vector<Room> *rooms = new std::vector<Room>();
    Room entryRoom = Room(static_cast<RoomType>(4));
    //rooms.push_back(entryRoom);
    long roomCount = rand() %10000 +1;
    std::cout << "Generating " << roomCount << " Rooms - Hold on!" << std::endl;
    std::vector<int>Trooms = std::vector<int>();
    std::vector<int>crossRooms = std::vector<int>();
    int roomsToCreate = roomCount;
    for(int i = 0;i < roomCount;i++)
    {
        Room currTmpRoom = Room(static_cast<RoomType>(rand() % 2));
        currTmpRoom.id = i;
        if(i = 0)
        {
            //This is the first room
            //currTmpRoom.rc = RoomConnector();
            currTmpRoom = Room(RoomType::entry);
            currTmpRoom.rc.backwards = -1;
            currTmpRoom.id = i;
            rooms->push_back(currTmpRoom);
            Room roomTwo = Room(RoomType::normal);
            roomTwo.id = i+1;
            roomTwo.rc.backwards = i;
            rooms->push_back(roomTwo);
            
        }
        else if(i = roomCount-1)
        {
            //this is the last room
            //currTmpRoom.rc = RoomConnector();
            currTmpRoom = Room(RoomType::normal);
            currTmpRoom.rc.forward = i+1;
            currTmpRoom.id = i;
            Room endRoom = Room(RoomType::exit);
            endRoom.id = i+1;
            endRoom.rc.backwards = i;
            endRoom.rc.forward = -1;
            
        }
        else
        {
            GenerateRoom(rooms,&roomsToCreate);
        }
        

    }
    Room exitRoom = Room(static_cast<RoomType>(5));
    rooms.push_back(exitRoom);
    Floor f = Floor();
    f.floorRooms = rooms;
    floors.push_back(f);
}
*/

/*
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
*/