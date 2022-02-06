//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#include "Room.h"

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// base constructor for a Room object
// all but 'name' have default values
Room::Room(string name, int capacity, int computers, bool whiteboard) {
    this->name = name;
    this->capacity = capacity;
    this->computers = computers;
    this->whiteboard = whiteboard;
}

// copy constructor for a Room object
Room::Room(Room &room) {
    this->name = room.getName();
    this->capacity = room.getCapacity();
    this->computers = room.getComputers();
    this->whiteboard = room.hasWhiteboard();
}

// deconstructor
Room::~Room() {

}

/**
 * Determine if this->room meets the given criteria
 * @param capacity the min capacity required to meet criteria
 * @param computers the min number of computer required to meet criteria
 * @param whiteboard whether a whiteboard is required.
 *        if a room has a whiteboard but is not required, it is ok
 * @return true if all criteria is met; else false
 */
bool Room::meetsCriteria(int capacity, int computers, bool whiteboard) {
    if (this->getCapacity() < capacity)
        return false;
    if (this->getComputers() < computers)
        return false;
    if (this->hasWhiteboard() == false && whiteboard == true)
        return false;

    return true;
}

// return true if this->name comes before
// room.name alphabetically; else false
/**
 * Determine if this->room comes before given Room&room where we compare the names alphabetically
 * @param room the Room to compare this->room to
 * @return true if this->room.name is alphabetically lessThan room.name; else false
 */
bool Room::lessThan(Room &room) {
    string s1 = this->getName();
    string s2 = room.getName();
    return (strcmp(s1.c_str(), s2.c_str()) < 0);
}

/**
 * Print the data of this->room including: capacity, num computers, hasWhiteboard
 *
 * @see getCapacity()
 * @see getComputers()
 * @see hasWhiteboard()
 */
void Room::print() {
    cout << "Room: " << this->getName()
         << " | Capacity: " << this->getCapacity()
         << " | Computers: " << this->getComputers()
         << " | Whiteboard: " << (this->hasWhiteboard() ? "yes" : "no")
         << endl;
}

// getters

string Room::getName() { return this->name; }
int Room::getCapacity() { return this->capacity; }
int Room::getComputers() { return this->computers; }
bool Room::hasWhiteboard() { return this->whiteboard; }
