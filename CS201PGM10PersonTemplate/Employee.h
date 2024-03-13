//
// Created by Johnny Diep on 3/7/24.
//

#ifndef CS201_PROGRAM10_PERSON_POWERSTAR0_EMPLOYEE_H
#define CS201_PROGRAM10_PERSON_POWERSTAR0_EMPLOYEE_H

#include "Staff.h"


class Employee : public Staff {
private:
    float vacHours;

public:
    Employee() : Staff(){
        type = 'E';
        vacHours = 0.0;
        totalEmployees++;
    }

    Employee(char t, string l, string f, int a, int h, float hr, float v)
            : Staff(t,l,f,a,h,hr){
        type = 'E';
        vacHours = v;
        totalEmployees++;
    }
    float getVacHours(){return vacHours;}
    void setVacHours(float v){vacHours = v;}
    void print() {
        cout << type << left << setw(5) << " "
             << setw(16) << lname
             << setw(15) << fname
             << setw(10)  << age
             << setw(5) << hours << ", " << hrlyRate << ", " << vacHours << endl;
    }
    static int totalEmployees;
};

#endif //CS201_PROGRAM10_PERSON_POWERSTAR0_EMPLOYEE_H
