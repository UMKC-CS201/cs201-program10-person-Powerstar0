//
// Created by Johnny Diep on 3/12/24.
//


#ifndef CS201_PROGRAM10_PERSON_POWERSTAR0_PET_H
#define CS201_PROGRAM10_PERSON_POWERSTAR0_PET_H
// Used CHATGPT to help construct the Class
#include <string>
#include <vector>
using namespace std;

class Pet {
private:
    string name;
    string type;
public:
Pet(string& petName, string& petType);

// Function declarations for getName and getType
    std::string getName() const;
    std::string getType() const;
};

#endif //CS201_PROGRAM10_PERSON_POWERSTAR0_PET_H
