/* Implementing class Rabbit */

#include "rabbit.h"

// method to convert enum breed to string

std::string rabbit_enum_to_string(Rabbit_breed rabbit){
    switch(rabbit){
        case American:
        return "American";
        case Belgian:
        return "Belgian";
        case Californian:
        return "Californian";
        case Dutch:
        return "Dutch";
        case Angora:
        return "Angora";
        case Harlequin:
        return "Harlequin";
        case Lionhead:
        return "Lionhead";
        case Tan:
        return "Tan";

        default:
        return "Invalid Rabbit breed";

    }
}

// Constructor
Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age):
Animal{std::string name, Gender gender, int age}, _breed{breed}{}

// Destructor
~Rabbit::Rabbit(){}


// getter for family of the object
std::string Rabbit::family() override {
    return "Rabbit";
}

// getter for the breed of the object
std::string Rabbit::breed() override {
    return rabbit_enum_to_string(_breed);
}

// pure virtual method to convert the object into string
virtual std::string Rabbit::to_string(){
    std::string temp1;
    temp1 = static_cast<Animal>(*this).to_string()+" "+rabbit_enum_to_string(_breed);
    return temp1;
}

