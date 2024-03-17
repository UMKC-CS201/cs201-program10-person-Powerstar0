//
// Created by Johnny Diep on 3/5/24.
//
#ifndef CS201_PROGRAM10_PERSON_POWERSTAR0_STUDENT_H
#define CS201_PROGRAM10_PERSON_POWERSTAR0_STUDENT_H

#include "Person.h"

class Student : public Person {
private:

    float gpa;

public:
    Student();
    Student(string l, string f, int a, float g);
    Student(string l, string f, int a, float g, vector<Pet *> pets);
    float getGPA() { return gpa; }
    void setGPA(float g) { gpa = g; }

    void print();
    void print(ofstream& outfile);
    static int totalStudents;
};

#endif //CS201_PROGRAM10_PERSON_POWERSTAR0_STUDENT_H
