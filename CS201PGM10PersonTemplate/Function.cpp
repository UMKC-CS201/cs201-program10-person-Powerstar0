#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Function.h"
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"
#include "Pet.h"

int readFile(vector<Person>& people, vector<Student>& students, vector<Teacher>& teachers, vector<Employee>& employees, vector<Person*> &allPeople, ofstream& outfile) {

  //OPEN THE INPUT FILE
	ifstream inFile;
	inFile.open("people.txt");
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
    vector<Pet*> pets;
    try{
        if (row[0][0] == 'S') {
            for (size_t i = 5; i < row.size(); i += 2) {
                if (row[i] != "none") {
                    string petName = row[i];
                    string petType = row[i + 1];
                    pets.push_back(new Pet(petName, petType));
                }
                else {
                    string petName = "none";
                    string petType;
                    pets.push_back(new Pet(petName, petType));
                }
            }
            Student tempS(row[1], row[2], stoi(row[3]), stof(row[4]), pets);
            students.push_back(tempS);
            Student* tempSP = new Student(row[1], row[2], stoi(row[3]), stof(row[4]), pets);
            allPeople.push_back(tempSP);
        }
        else if (row[0][0] == 'T') {
            //
            for (size_t i = 7; i < row.size(); i += 2) {
                if (row[i] != "none") {
                    string petName = row[i];
                    string petType = row[i + 1];
                    pets.push_back(new Pet(petName, petType));
                }
                else {
                    string petName = "none";
                    string petType;
                    pets.push_back(new Pet(petName, petType));
                }
            }
            //
            Teacher tempT('T', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6], pets);
            teachers.push_back(tempT);
            Teacher* tempTP = new Teacher('T', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6], pets);
            allPeople.push_back(tempTP);
        }
        else if (row[0][0] == 'E') {
            //
            for (size_t i = 7; i < row.size(); i += 2) {
                if (row[i] != "none") {
                    string petName = row[i];
                    string petType = row[i + 1];
                    pets.push_back(new Pet(petName, petType));
                }
                else {
                    string petName = "none";
                    string petType;
                    pets.push_back(new Pet(petName, petType));
                }
            }
            //
            Employee tempE('E', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stoi(row[6]), pets);
            employees.push_back(tempE);
            Employee* tempEP = new Employee('E', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stoi(row[6]), pets);
            allPeople.push_back(tempEP);
        }
        else {
            for (size_t i = 4; i < row.size(); i += 2) {
                if (row[i] != "none") {
                    string petName = row[i];
                    string petType = row[i + 1];
                    pets.push_back(new Pet(petName, petType));
                }
                else {
                    string petName = "none";
                    string petType;
                    pets.push_back(new Pet(petName, petType));
                }
        }
            Person tempP(row[1],row[2],stoi(row[3]), pets);
            // if valid, push the object onto the vector
            people.push_back(tempP);
            Person* tempPP = new Person(row[1],row[2],stoi(row[3]), pets);
            allPeople.push_back(tempPP);
        }
    }
    catch(...){
      outfile << "RECORD: " << inRec << " IS IN ERROR\n";
    }
  }
	inFile.close();
	return 0;
}

// write the code to print the vector (Changed instead to write to output file)
// Corrections made to math becuase of total persons becuase it double counted.
void printVector(vector<Person> people, ofstream& outfile) {

  outfile << "TYPE " << setw(11) << "LAST NAME"
  << setw(17) << "FIRST NAME" << setw(8) << "AGE"
  << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < people.size(); i++)
      people.at(i).print(outfile);

  outfile << "\nTOTAL PEOPLE: " << (Person::totalPeople - Student::totalStudents - Teacher::totalTeacher - Employee::totalEmployees) / 2 << endl;
}

void printVector(vector<Student> student) {

    cout << "TYPE  " << setw(15) << "LAST NAME"
         << setw(16) << "FIRST NAME" << setw(8) << "AGE"
         << setw(48) << "OTHER INFO" << setw(60) << "PETS" << endl;
    for (int i = 0; i < student.size(); i++)
        student.at(i).print();
    cout << "\nTOTAL PEOPLE: " << Student::totalStudents / 2 << endl;
}

void printVector(vector<Student> student, ofstream& outfile) {

    outfile << "TYPE  " << setw(15) << "LAST NAME"
         << setw(16) << "FIRST NAME" << setw(8) << "AGE"
         << setw(48) << "OTHER INFO" << setw(60) << "PETS" << endl;
    for (int i = 0; i < student.size(); i++)
        student.at(i).print(outfile);
    outfile << "\nTOTAL STUDENTS: " << Student::totalStudents / 2 << endl;
}

void printVector(vector<Teacher> teacher, ofstream& outfile) {

    outfile << "TYPE  " << setw(15) << "LAST NAME"
         << setw(16) << "FIRST NAME" << setw(8) << "AGE"
         << setw(48) << "OTHER INFO" << setw(60) << "PETS" << endl;
    for (int i = 0; i < teacher.size(); i++)
        teacher.at(i).print(outfile);

    outfile << "\nTOTAL TEACHERS: " << Teacher::totalTeacher / 2 << endl;
}

void printVector(vector<Employee> employee, ofstream& outfile) {

    outfile << "TYPE  " << setw(15) << "LAST NAME"
         << setw(16) << "FIRST NAME" << setw(8) << "AGE"
         << setw(48) << "OTHER INFO" << setw(60) << "PETS" << endl;
    for (int i = 0; i < employee.size(); i++)
        employee.at(i).print(outfile);

    outfile << "\nTOTAL EMPLOYEES: " << Employee::totalEmployees / 2 << endl;
}

void printVector(vector<Person*> all, ofstream& outfile) {

    outfile << "TYPE  " << setw(15) << "LAST NAME"
         << setw(16) << "FIRST NAME" << setw(8) << "AGE"
         << setw(48) << "OTHER INFO" << setw(60) << "PETS" << endl;
    for (int i = 0; i < all.size(); i++)
        all.at(i)->print(outfile);

    outfile << "\nTOTAL: " << Person::totalPeople/2 << endl;
}