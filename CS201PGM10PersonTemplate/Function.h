#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"
using namespace std;

int readFile(vector<Person>&,vector<Student>&, vector<Teacher>&, vector<Employee>&, vector<Person*> &all, ofstream& outfile);
void printVector(vector<Person>);
void printVector(vector<Student>);
void printVector(vector<Teacher>);
void printVector(vector<Employee>);
void printVector(vector<Person*>);
void printVector(vector<Person>, ofstream& outfile);
void printVector(vector<Student>, ofstream& outfile);
void printVector(vector<Teacher>, ofstream&outfile);
void printVector(vector<Employee>, ofstream& outfile);
void printVector(vector<Person*>, ofstream& outfile);