// CS201Wk8PersonClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Person.h"
#include "Function.h"


//add Static Member initialization


int main()
{
    //create a vector of Person type
    vector<Person> myPeeps;

    // read the file & load into vector of Personal type
    readFile(myPeeps);

    // print the vector
    printVector(myPeeps);

    //print total people (static variable from class)
}