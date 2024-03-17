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

Student::Student(string l, string f, int a, float g, vector<Pet*> v)
: Person(l, f, a, v) {
    type = 'S';
    gpa = g;
    totalStudents++;
    pets = v;
}

void Student::print() {
    cout << type << left << setw(5) << " "
         << setw(16) << lname
         << setw(15) << fname
         << setw(10) << age
         << setw(4) << "GPA:" << setw(42) << gpa;
    for (const auto& pet : pets) {
        cout << setw(11) << pet->getName() <<" (" << pet->getType() << ") ";
    }
    cout << endl;
}

void Student::print(ofstream &outfile) {
    outfile << type << left << setw(5) << " "
         << setw(16) << lname
         << setw(15) << fname
         << setw(10) << age
         << setw(4) << "GPA:" << setw(42) << gpa;
    for (const auto& pet : pets) {
        outfile << setw(11) << pet->getName() <<" (" << pet->getType() << ") ";
    }
    outfile << endl;
}

