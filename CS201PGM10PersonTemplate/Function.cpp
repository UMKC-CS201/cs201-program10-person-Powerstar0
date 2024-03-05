#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Function.h"

int readFile(vector<Person>& people) {

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
    try{
      Person tempP(row[1],row[2],stoi(row[3]));
      // if valid, push the object onto the vector
      people.push_back(tempP);
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
 
  cout << "TYPE" << setw(11) << "LAST NAME"
  << setw(17) << "FIRST NAME" << setw(8) << "AGE"
  << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < people.size(); i++)
      people.at(i).print();  
}