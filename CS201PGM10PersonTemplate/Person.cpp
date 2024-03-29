#include <iostream>
#include <iomanip>
#include <string>

#include "Person.h"
using namespace std;

//default constructor
Person::Person() {      //scope identifier Person::
    type  = 'P';
	lname = " ";
	fname = " ";
	age = 0;
    totalPeople++;
}

//correct the overloaded constructor
Person::Person(string l, string f, int a) {
    type  = 'P';
    lname = l;
    fname = f;
    age = a;;
    totalPeople++;
}

Person::Person(string l, string f, int a, vector<Pet*> &p) {
  type  = 'P';
  lname = l;
  fname = f;
  age = a;
  pets = p;
  totalPeople++;
}

//update this to print neatly
void Person::print () {
	//cout << "Name: " << fname << " " << lname << endl;
	//cout << "Age:  " << age << endl << endl;
    cout << type << left << setw(5) << " "
    << setw(16) << lname
    << setw(15) << fname
    << setw(49) << age;
    for (const auto& pet : pets) {
        cout << pet->getName() << " (" << pet->getType() << "), ";
    }
    cout << endl;
}

void Person::print (ofstream& outfile) {
    //cout << "Name: " << fname << " " << lname << endl;
    //cout << "Age:  " << age << endl << endl;
    outfile << type << left << setw(5) << " "
         << setw(16) << lname
         << setw(15) << fname
         << setw(56) << age;
    for (const auto& pet : pets) {
        outfile << setw(11) << pet->getName() << " (" << pet->getType() << ") ";
    }
    outfile << endl;
}
