#pragma once
#include <string>
#include "Pet.h"
using namespace std;
//Used CHATGPT to aid in creating PET class

class Person {
protected:

    char type;
	string lname;
	string fname;
	int age;
    vector<Pet*> pets;

public:
	Person();                            //constructor: default
    Person(string l, string f, int a);
	Person(string l, string f, int a, vector<Pet*>& pet);   //constructor: overloaded (needs correction)

  //add other accessors & mutators
	string getFName() { return fname; }         //accessor (first name)
    string getLName() { return lname; }
    int getAge() { return age; }
    vector<Pet*>& getPets() {return pets;}

	void setFName(string f) { fname = f; }    //mutator (first name)
    void setLName(string l) { lname = l; }
    void setAge(int a) { this->age = a; }
    void SetPets(vector<Pet*>& pet) {pets = pet;}

	virtual void print();

  // add static member to count Persons created
  // where would this be updated?
    static int totalPeople;
};
