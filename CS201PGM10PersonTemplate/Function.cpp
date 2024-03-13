#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Function.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"

int readFile(vector<Person>& people, vector<Student>& students, vector<Teacher>& teachers, vector<Employee>& employees, vector<Person*> &allPeople) {

  //OPEN THE INPUT FILE
	ifstream inFile;
	inFile.open("/Users/johnnydiep/CLionProjects/cs201-program10-person-Powerstar0/CS201PGM10PersonTemplate/people.txt");
	if (!inFile.is_open()) {
		cout << "File is not open" << endl;
		return 1;
	}

  //SET TEMPORARY VARIABLES FOR INPUTTING PERSON INFORMATION
	int tempAge;
	float tempGPA;
	string inRec, tempStr;
	vector <string> row;

  //LOOP THROUGH THE INPUT FILE
	while (getline(inFile, inRec)) {
    //CHANGE THE INPUT RECORD inRec TO BECOME STRING STREAM inSS
    //THIS WILL ALLOW US TO USE THE RECORD inRec AS THOUGH IT IS
    //AN INPUT STREAM (USEFUL WHEN INPUT IS NOT FIXED)
		stringstream inSS(inRec);
		row.clear();
    // loop through string stream, partioning on ','
    // push each string onto the row vector
		while (getline(inSS, tempStr, ',')) {
			row.push_back(tempStr);
		}
    // try to create a person object 
    // calling constructor with lastname row[1], firstname row[2] and age
    // convert the string 'age' to an integer
    try{
        if (row[0][0] == 'S') {
            Student tempS(row[1], row[2], stoi(row[3]), stof(row[4]));
            students.push_back(tempS);
            Student* tempSP = new Student(row[1], row[2], stoi(row[3]), stof(row[4]));
            allPeople.push_back(tempSP);
        }
        else if (row[0][0] == 'T') {
            Teacher tempT('T', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6]);
            teachers.push_back(tempT);
            Teacher* tempTP = new Teacher('T', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6]);
            allPeople.push_back(tempTP);
        }
        else if (row[0][0] == 'E') {
            Employee tempE('E', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stoi(row[6]));
            employees.push_back(tempE);
            Employee* tempEP = new Employee('E', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stoi(row[6]));
            allPeople.push_back(tempEP);
        }
        else {
            Person tempP(row[1],row[2],stoi(row[3]));
            // if valid, push the object onto the vector
            people.push_back(tempP);
            Person* tempPP = new Person(row[1],row[2],stoi(row[3]));
            allPeople.push_back(tempPP);
        }
    }
    catch(...){
      cout << "RECORD: " << inRec << " IS IN ERROR\n";
    }
  }
	inFile.close();
	return 0;
}

// write the code to print the vector
void printVector(vector<Person> people) {

  cout << "TYPE " << setw(11) << "LAST NAME"
  << setw(17) << "FIRST NAME" << setw(8) << "AGE"
  << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < people.size(); i++)
      people.at(i).print();

  cout << "\nTOTAL PEOPLE: " << Person::totalPeople << endl;
}

// write the code to print the vector
void printVector(vector<Student> student) {

    cout << "TYPE " << setw(11) << "LAST NAME"
         << setw(17) << "FIRST NAME" << setw(8) << "AGE"
         << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
    for (int i = 0; i < student.size(); i++)
        student.at(i).print();

    cout << "\nTOTAL PEOPLE: " << Student::totalStudents << endl;
}

void printVector(vector<Teacher> teacher) {

    cout << "TYPE " << setw(11) << "LAST NAME"
         << setw(17) << "FIRST NAME" << setw(8) << "AGE"
         << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
    for (int i = 0; i < teacher.size(); i++)
        teacher.at(i).print();

    cout << "\nTOTAL TEACHERS: " << Teacher::totalTeacher << endl;
}

void printVector(vector<Employee> employee) {

    cout << "TYPE " << setw(11) << "LAST NAME"
         << setw(17) << "FIRST NAME" << setw(8) << "AGE"
         << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
    for (int i = 0; i < employee.size(); i++)
        employee.at(i).print();

    cout << "\nTOTAL EMPLOYEES: " << Employee::totalEmployees << endl;
}

void printVector(vector<Person*> all) {

    cout << "TYPE " << setw(11) << "LAST NAME"
         << setw(17) << "FIRST NAME" << setw(8) << "AGE"
         << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
    for (int i = 0; i < all.size(); i++)
        all.at(i)->print();

    cout << "\nTOTAL: " << Person::totalPeople << endl;
}