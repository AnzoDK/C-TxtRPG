#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "character.h"
#include "roomConnector.h"
class RoomConnector;

enum RoomType{normal,Troom,crossRoom,exit_room,entry,dead_end};

class RoomEvent
{
    public:
        RoomEvent()
        {
            PreInit();
            Init();
        }
        virtual void Init();
        virtual int Event();
        virtual void useOptions(std::string input, Character* c);
        std::string getEventName();
    private:
        std::string options;
        std::string eventName;
        void PreInit();
};

class Ambush : public RoomEvent
{
    public:
        virtual void Init() override;
        virtual int Event() override;
        virtual void useOptions(std::string input, Character* c) override;
    private:
        std::string options;
        std::string eventName;
};

class Room
{
    public:
        Room(){connected = false;};
        Room(RoomType T)
        {
            init(T);
        };
        long roomCount;
        virtual void OnEnter();
        //Sadly we must live without this feature...
        int id;
        RoomType getRoomType();
        RoomConnector* rc;
        RoomEvent re;
        bool connected;
    private:
        RoomType rt;
        void init(RoomType T);
};

class Safezone : public Room
{
    public:
        virtual void OnEnter() override
        {
            std::cout << "You have entered a safezone - Stay here for as long as you'd like" << std::endl
            << "You will heal 1 health every tick in here" << std::endl;
        }
};

class Floor
{
    public:
        //long floorCount;
        std::vector<Room> floorRooms;
};

class Dungeon
{
    public:
        //void GenerateLayout(int entryID,int exitID,Floor f,std::default_random_engine rng);
        //void GenerateFloors();
        //void GenerateRooms();   
        //std::vector<Floor> floors;
        int floorID;
        Room* currentRoom;
        Room* GenerateRoom();
        void DeleteRooms();
        std::vector<Room*> rooms;
        //unsigned long dungeonsBeat;
    private:
        //int GenerateRoom(std::vector<Room> *rs, int *createCounter);
        
};