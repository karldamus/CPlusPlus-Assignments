//
// Created by Karl Damus on 2/3/2022.
//

// Author: Karl Damus

#ifndef ASSIGNMENT_1_STUDENT_H
#define ASSIGNMENT_1_STUDENT_H

#include <string>

using namespace std;

class Student {
    public:
        // constructors
        Student();
        Student(std::string name, std::string number);
        Student(Student &student);
        ~Student();

        // getters
        std::string getName();
        std::string getNumber();

        // setters
        void setName(std::string name);
        void setNumber(std::string number);

        // other
        bool lessThan(Student &s);
        void print();

    private:
        std::string name;
        std::string number;
};


#endif //ASSIGNMENT_1_STUDENT_H
