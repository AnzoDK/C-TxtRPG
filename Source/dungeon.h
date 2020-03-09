#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "character.h"
enum RoomType{normal,Troom,crossRoom,exit,entry,dead_end};

class RoomEvent
{
    public:
        RoomEvent();
        virtual void Init();
        virtual int Event();
        virtual void useOptions(std::string input, Character* c);
        std::string getEventName();
    private:
        std::string options;
        std::string eventName;
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
        Room(){};
        Room(RoomType T);
        long roomCount;
        virtual void OnEnter();
        //Sadly we must live without this feature...
        int id;
        RoomType getRoomType();
        RoomConnector rc;
        RoomEvent re;
    private:
        RoomType rt;
};

class Safezone : Room
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

class RoomConnector
{
    public:
        RoomConnector();
        //int right;
        //int left;
        //int forward;
        //int backwards;
        Room r_right = Room();
        Room r_left = Room();
        Room r_forward = Room();
        Room r_backwards = Room();
        //long comesFrom;
};

class Dungeon
{
    public:
        //void GenerateLayout(int entryID,int exitID,Floor f,std::default_random_engine rng);
        //void GenerateFloors();
        //void GenerateRooms();   
        //std::vector<Floor> floors;
        int floorID;
        Room currentRoom;
        Room GenerateRoom();
        //unsigned long dungeonsBeat;
    private:
        //int GenerateRoom(std::vector<Room> *rs, int *createCounter);
        
};