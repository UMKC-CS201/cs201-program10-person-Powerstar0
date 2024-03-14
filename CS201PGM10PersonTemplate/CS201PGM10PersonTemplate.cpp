// CS201Wk8PersonClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Name: Johnny Diep
//Date: 03/14/2024
//Purpose: List types of people, their names, age, other info, and pets
//Note: Used CHATGPT to help make the Pet Class



#include "Person.h"
#include "Function.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"


//add Static Member initialization
int Person::totalPeople = 0;
int Student::totalStudents = 0;
int Teacher::totalTeacher = 0;
int Employee::totalEmployees = 0;

int main()
{
    //create a vector of Person type
    vector<Person> myPeeps;
    vector<Student> myStudents;
    vector<Teacher> myTeachers;
    vector<Employee> myEmployees;
    vector<Person*> allPeople;

    // read the file & load into vector of Personal type
    readFile(myPeeps, myStudents, myTeachers, myEmployees, allPeople);

    /*
    Person newP;
    newP.setLName("Wonka");
    newP.setFName("Willy");
    newP.setAge(30);
    myPeeps.push_back(newP);
    Person newP2("Mahomes", "Patrick", 25);
    myPeeps.push_back(newP2);
     */

    // print the vector
    printVector(myPeeps);
    printVector(myStudents);
    printVector(myTeachers);
    printVector(myEmployees);
    printVector(allPeople);

    //print total people (static variable from class)
}