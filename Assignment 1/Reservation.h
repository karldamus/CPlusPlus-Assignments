//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#ifndef ASSIGNMENT_1_RESERVATION_H
#define ASSIGNMENT_1_RESERVATION_H

#include "Student.h"
#include "Room.h"
#include "Date.h"

#include <string>

class Reservation {
    public:
        // constructor
        Reservation(Student *student, Room *room, Date &date);
        ~Reservation();

        // getters
        Student getStudent();
        Room getRoom();
        Date getDate();

        // other
        bool lessThan(Reservation &res);
        bool overlaps(const string &r, Date &d);
        void print();

    private:
        Student *student;
        Room *room;
        Date date;
};


#endif //ASSIGNMENT_1_RESERVATION_H
