//
// Created by Johnny Diep on 3/7/24.
//

#ifndef CS201_PROGRAM10_PERSON_POWERSTAR0_TEACHER_H
#define CS201_PROGRAM10_PERSON_POWERSTAR0_TEACHER_H

#include "Staff.h"

class Teacher : public Staff {
private:
    string subject;

public:
    Teacher() : Staff(){
        type = 'T';
        subject = " ";
        totalTeacher++;
    }

    Teacher(char t, string l, string f, int a, int h, float hr, string sub, vector<Pet*> p)
    : Staff(t,l,f,a,h,hr,p){
        type = 'T';
        subject = sub;
        totalTeacher++;
    }
    string getSub(){return subject;}
    void setSub(string s){subject = s;}
    void print() {
    cout << type << left << setw(5) << " "
         << setw(16) << lname
         << setw(15) << fname
         << setw(10)  << age
         << setw(5) << "HRLY:" << setw(5) << hrlyRate << "  SUBJECT:" << setw(26) << subject;
        for (const auto& pet : pets) {
            cout << pet->getName() << " (" << pet->getType() << ") ";
        }
        cout << endl;
}
void print(ofstream& outfile) {
    outfile << type << left << setw(5) << " "
         << setw(16) << lname
         << setw(15) << fname
         << setw(10)  << age
         << setw(5) << "HRLY:" << setw(5) << hrlyRate << "  SUBJECT:" << setw(26) << subject;
    for (const auto& pet : pets) {
        outfile << setw(11) << pet->getName() << " (" << pet->getType() << ") ";
    }
    outfile << endl;
    }
static int totalTeacher;
};

#endif //CS201_PROGRAM10_PERSON_POWERSTAR0_TEACHER_H
