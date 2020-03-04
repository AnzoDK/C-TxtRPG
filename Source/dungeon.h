#pragma once
#include <iostream>
#include <vector>
enum RoomType{normal,Troom,crossRoom,exit,entry};

class Room
{
    public:
        Room(){};
        Room(RoomType T);
        long roomCount;
        virtual void OnEnter();
        long id;
        RoomType getRoomType();
        RoomConnector rc;
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
        int right;
        int left;
        int forward;
        int backwards;
        //long comesFrom;
};

class Layout
{
    public:
        
};

class Dungeon
{
    public:
        void GenerateLayout(int entryID,int exitID,Floor f,std::default_random_engine rng);
        void GenerateFloors();
        void GenerateRooms();
        std::vector<Floor> floors;
        unsigned long dungeonsBeat;
    private:
        
};