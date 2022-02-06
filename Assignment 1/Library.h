//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#ifndef ASSIGNMENT_1_LIBRARY_H
#define ASSIGNMENT_1_LIBRARY_H

#include "Student.h"
#include "Date.h"
#include "Room.h"
#include "Reservation.h"

#include <string>

using namespace std;

const int ARRAY_SIZE = 50;

class Library {
    public:
        // constructor
        Library();
        // destructor
        ~Library();

        // create
        bool addStudent(const std::string &name, const std::string &number);
        bool addRoom(std::string name, int capacity=1, int computers=0, bool whiteboard=false);
        bool makeReservation(const std::string &student, const std::string &room, Date &date);

        // getters -- complex
        bool getStudent(const std::string &name, Student **student);
        bool getRoom(const std::string &roomName, Room **room);
        bool isFree(const std::string &room, Date &date);

        // getters -- simple
        int getNumStudents();
        int getNumRooms();
        int getNumReservations();

        // other
        void update(Date &date);
        void printReservations();

        // inc -- increment each counter
        // by n (default 1)
        void incNumStudents(int n=1);
        void incNumRooms(int n=1);
        void incNumReservations(int n=1);


    private:
        Student** students;;
        Room** rooms;
        Reservation** reservations;

        int numStudents;
        int numRooms;
        int numReservations;
};


#endif //ASSIGNMENT_1_LIBRARY_H
