//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#include "Library.h"

#include "Student.h"
#include "Date.h"
#include "Room.h"
#include "Reservation.h"

using namespace std;

// constructor
Library::Library() {
    // init arrays
    students = new Student*[ARRAY_SIZE];
    rooms = new Room*[ARRAY_SIZE];
    reservations = new Reservation*[ARRAY_SIZE];

    // init counters
    numStudents = 0;
    numRooms = 0;
    numReservations = 0;
}

// destructor
Library::~Library() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
      delete students[i];
      delete rooms[i];
      delete reservations[i];
    }
    delete[] students;
    delete[] rooms;
    delete[] reservations;
}

/**
 * Add a Student to the Student array if space is available
 * @param name the student's name
 * @param number the student number
 * @return true if successful; false if no space is available
 */
bool Library::addStudent(const string &name, const string &number) {
    if (getNumStudents() == ARRAY_SIZE)
        return false;

    Student* student = new Student(name, number);

    // todo: implement ordering by number

    students[getNumStudents()] = student;

    incNumStudents();

    return true;
}

/**
 * Add a Room to the Room array if space is available
 * @param name the room name
 * @param capacity the max capacity of the room
 * @param computers the number of available computers in the room
 * @param whiteboard true if whiteboard is available; else false
 * @return true if successful; false if no space is available
 */
bool Library::addRoom(string name, int capacity, int computers, bool whiteboard) {
    if (getNumRooms() == ARRAY_SIZE)
        return false;

    Room* room = new Room(name, capacity, computers, whiteboard);

    // todo: implement ordering by number

    rooms[getNumRooms()] = room;

    incNumRooms();

    return true;
}

/**
 * Create and add a Reservation to the Reservation array:
 *      <li>IF: a Student with name #student exists</li>
 *      <li>&IF: a Room with name #room exists</li>
 *      <li>&IF: there is space in the Reservation array</li>
 *      <li>&IF: the Room with name #room Library#isFree()</li>
 * @param student the name of a Student that must exist
 * @param room the name of a Room that must exist
 * @param date the Date for the new Reservation;
 *        also used to determine if the Room isFree()
 * @return true if Reservation is successfully added;
 *         false if any above-mentioned conditions are not met
 *
 * @see Library::isFree()
 */
bool Library::makeReservation(const string &student, const string &room, Date &date) {
    int studentIndex = -1;
    int roomIndex = -1;

    // loop through Student array
    for (int i = 0; i < getNumStudents(); i++) {
        if (students[i]->getName() == student) {
            // student found
            studentIndex = i;
            break;
        }
    }

    // loop through Room array
    for (int i = 0; i < getNumRooms(); i++) {
        if (rooms[i]->getName() == room) {
            // room found
            roomIndex = i;
            break;
        }
    }

    // if student or room does not exist
    // return false as we cannot make a reservation
    if (studentIndex == -1 || roomIndex == -1)
        return false;

    // if Reservation array is full
    if (getNumReservations() == ARRAY_SIZE)
        return false;

    // if room is free
    if (isFree(rooms[roomIndex]->getName(), date)) {
        // todo: implement ordering by lessThan function
        // create a new Reservation and add to Reservation array
        Reservation* reservation = new Reservation(students[studentIndex], rooms[roomIndex], date);
        reservations[getNumReservations()] = reservation;

        // increment the number of reservations
        incNumReservations();

        return true;
    } else {
        // room is not free
        return false;
    }
}

// getters -- complex

/**
 * Get a Student from the Student array with given &name
 * @param name the name of the Student to find
 * @param student the location to store the found Student
 * @return true if Student with name &name is found; else false
 */
bool Library::getStudent(const string &name, Student **student) {
    // loop through Student array
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->getName() == name) {
            student = new Student*(students[i]);
            return true;
        }
    }

    return false;
}

/**
 * Get a Room from the Room array with given &roomName
 * @param roomName the name of the Room to find
 * @param room the location to store the found Room
 * @return true if Room with name &roomName is found; else false
 */
bool Library::getRoom(const string &roomName, Room **room) {
    // loop through Room array
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i]->getName() == roomName) {
            room = new Room*(rooms[i]);
            return true;
        }
    }

    return false;
}

/**
 * Determine if a Room &room is free on a given Date &date
 * @param room the name of the Room
 * @param date the timeslot to determine whether the Room &room is free
 * @return true if the room exists, and is free (or if no reservations have been made yet); else false
 */
bool Library::isFree(const string &room, Date &date) {
    // loop through Room array
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i]->getName() == room) {
            // found the room; determine if there
            // exists a reservation for room that overlaps date
            for (int j = 0; j < numReservations; j++) {
                if (reservations[j]->getRoom().getName() == room) {
                    // found reservation with room
                    // determine if overlap exists
                    if (reservations[j]->getDate().overlaps(date))
                        return false; // overlap exists
                    else
                        return true; // overlap doesn't exist
                }
            }
            return true; // no reservations have been made yet, return true
        }
    }

    return false;
}

// getters -- simple
int Library::getNumStudents() { return this->numStudents; }
int Library::getNumRooms() { return this->numRooms; }
int Library::getNumReservations() { return this->numReservations; }

// other
void Library::update(Date &date) {
    // todo: implement as bonus -- see part 10 of A1.Library outline
}

/**
 * Print all Reservation objects from the Reservation array
 */
void Library::printReservations() {
    // loop through Reservation array
    for (int i = 0; i < getNumReservations(); i++) {
        reservations[i]->print();

        cout << endl;
    }
    cout << "   ===========" << endl;
    cout << endl;
}

// inc
void Library::incNumStudents(int n) { numStudents += n; }
void Library::incNumRooms(int n) { numRooms += n;}
void Library::incNumReservations(int n) { numReservations += n;}
