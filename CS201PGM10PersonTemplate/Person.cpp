#include <iostream>
#include <iomanip>
#include <string>

#include "Person.h"

//default constructor
Person::Person() {
  type  = 'P';
	lname = " ";
	fname = " ";
	age = 0;
}

//correct the overloaded constructor
Person::Person(string l, string f, int a) {
  type  = 'P';
  lname = " ";
  fname = " ";
  age = 0;
}

//update this to print neatly
void Person::print () {
	cout << "Name: " << fname << " " << lname << endl;
	cout << "Age:  " << age << endl << endl;
}