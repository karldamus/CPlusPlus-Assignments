//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#include "Reservation.h"

#include "Student.h"
#include "Room.h"
#include "Date.h"

#include <string>
#include <iostream>

// single constructor
Reservation::Reservation(Student *student, Room *room, Date &date) {
    this->student = new Student(*student);
    this->room = new Room(*room);
    this->date.setDate(date);
}

// deconstructor
Reservation::~Reservation() {
  delete student;
  delete room;
}

// getters
Student Reservation::getStudent() { return *student; }
Room Reservation::getRoom() { return *room; }
Date Reservation::getDate() { return date; }

/**
 * Determine if a given Reservation comes after the Reservation object that called the method
 * @param res the Reservation to compare
 * @return true if this->date comes before res.date; else false
 *
 * @see Date::lessThan(Date&)
 */
bool Reservation::lessThan(Reservation &res) {
  // Date tmp = Date(res.getDate());
    return date.lessThan(res.date);
}

/**
 * Determine if this->date overlaps Date& d
 * @param r the name of the Room to match
 * @param d the Date to compare
 * @return  true if the r argument matches the name of the room member
 *          variable and this.date overlaps d, and false otherwise.
 *
 * @see Date::overlaps(Date&)
 */
bool Reservation::overlaps(const string &r, Date &d) {
    if (r == getRoom().getName()) {
        if (getDate().overlaps(d))
            return true;
    }

    return false;
}

/**
 * Print this Reservation with the date, student, and room
 *
 * @see Date::print()
 * @see Student::print()
 * @see Room::print()
 */
void Reservation::print() {
    cout << "Reservation on: " << endl;
    cout << "   "; getDate().print();
    cout << "   "; getStudent().print();
    cout << "   "; getRoom().print();
}
