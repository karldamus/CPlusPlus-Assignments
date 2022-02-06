//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#ifndef TUTORIAL3_ROOM_H
#define TUTORIAL3_ROOM_H

#include <string>

using namespace std;

class Room {
    public:
        // constructors
        Room(std::string name, int capacity=1, int computers=0, bool whiteboard=false);
        Room(Room &room);
        ~Room();

        // getters
        std::string getName();
        int getCapacity();
        int getComputers();
        bool hasWhiteboard();

        // other
        bool meetsCriteria(int capacity, int computers=0, bool whiteboard=false);
        bool lessThan(Room &room);
        void print();

    private:
        std::string name;
        int capacity;
        int computers;
        bool whiteboard;
};

#endif //TUTORIAL3_ROOM_H
