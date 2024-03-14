//
// Created by Johnny Diep on 3/12/24.
//
// Used CHATGPT to help construct the class
#include "Pet.h"

Pet::Pet(string& petName, string& petType) {
    name = petName;
    type = petType;
}

string Pet::getName() const {
    return name;
}

string Pet::getType() const {
    return type;
}