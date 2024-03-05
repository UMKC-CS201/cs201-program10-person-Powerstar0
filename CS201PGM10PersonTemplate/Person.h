#pragma once
#include <string>
using namespace std;

class Person {
private:
  char type; 
	string lname;
	string fname;
	int age;

public:
	Person();                            //constructor: default
	Person(string l, string f, int a);   //constructor: overloaded (needs correction)

  //add other accessors & mutators
	string getFName() { return fname; }         //accessor (first name)

	void   setFName(string f) { fname = f; }    //mutator (first name)

	void print();

  // add static member to count Persons created
  // where would this be updated?
};
