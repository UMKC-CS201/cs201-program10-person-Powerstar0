//
// Created by Johnny Diep on 3/5/24.
//

#include "Student.h"
#include <iomanip>
#include <iostream>

Student::Student() : Person() {
    type = 'S';
    gpa = 0.0;
    totalStudents++;
}

Student::Student(string l, string f, int a, float g)
: Person(l, f, a) {
    type = 'S';
    gpa = g;
    totalStudents++;
}

void Student::print() {
    cout << type << left << setw(5) << " "
         << setw(16) << lname
         << setw(15) << fname
         << setw(10) << age
         << setw(5) << gpa << endl;
}