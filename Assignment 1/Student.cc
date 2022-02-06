//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#include "Student.h"

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// empty constructor
Student::Student() {
    setName("John Doe");
    setNumber("000000000");
}

// full constructor
Student::Student(string name, string number) {
    setName(name);
    setNumber(number);
}

// copy constructor
Student::Student(Student &student) {
    setName(student.getName());
    setNumber(student.getNumber());
}

// deconstructor
Student::~Student() {

}

/**
 * Determine, based on the student number, if this->number is numerically less than &s.number
 * @param s the given student to compare to this
 * @return true if this->number < s.number; else false
 */
bool Student::lessThan(Student &s) {
    string s1 = this->getNumber();
    string s2 = s.getNumber();
    return (strcmp(s1.c_str(), s2.c_str()) < 0);
}

/**
 * Print the details of this Student
 */
void Student::print() {
    cout << "Student " << getName() << " | " << getNumber() << endl;
}

// getters
string Student::getName() { return name; }
string Student::getNumber() { return number; }

// setters
void Student::setName(string name) { this->name = name; }
void Student::setNumber(string number) { this->number = number; }
