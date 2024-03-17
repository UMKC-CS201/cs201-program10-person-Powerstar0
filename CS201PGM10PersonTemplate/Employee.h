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

    Employee(char t, string l, string f, int a, int h, float hr, float v, vector<Pet*> p)
            : Staff(t,l,f,a,h,hr,p){
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
             << setw(9)  << age
             << setw(5)  << " HRLY:" << setw(5) <<hrlyRate << " VAC DAYS:" << setw(26) << vacHours;
        for (const auto& pet : pets) {
            cout << setw(11) << pet->getName() << " (" << pet->getType() << ") ";
        }
        cout << endl;
    }
    void print(ofstream& outfile) {
        outfile << type << left << setw(5) << " "
             << setw(16) << lname
             << setw(15) << fname
             << setw(9)  << age
             << setw(5)  << " HRLY:" << setw(5) <<hrlyRate << " VAC DAYS:" << setw(26) << vacHours;
        for (const auto& pet : pets) {
            outfile << setw(11) << pet->getName() << " (" << pet->getType() << ") ";
        }
        outfile << endl;
    }
    static int totalEmployees;
};

#endif //CS201_PROGRAM10_PERSON_POWERSTAR0_EMPLOYEE_H
