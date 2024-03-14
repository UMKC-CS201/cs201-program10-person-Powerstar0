//
// Created by Johnny Diep on 3/7/24.
//

#ifndef CS201_PROGRAM10_PERSON_POWERSTAR0_STAFF_H
#define CS201_PROGRAM10_PERSON_POWERSTAR0_STAFF_H

#include "Person.h"

class Staff : public Person{
protected:
    int hours;
    float hrlyRate;


public:
    Staff() : Person(){
        hours = 0;
        hrlyRate = 0.0;
    }
    Staff(char t, string l, string f, int a, int h, float hr, vector<Pet*> &P)
        : Person(l,f,a,P){
        type = ' ';
        hours = h;
        hrlyRate = hr;
        pets = P;
    }
    int getHours(){return hours;}
    float getHrlyRate(){return hrlyRate;}
    void setHours(int h){hours = h;}
    void setHrlyRate(float hr){hrlyRate = hr;}

    virtual void print() = 0;
};

#endif //CS201_PROGRAM10_PERSON_POWERSTAR0_STAFF_H
