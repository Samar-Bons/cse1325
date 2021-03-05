/* Implementing class Cat */

#include "cat.h"

// method to convert enum breed to string
std::string cat_enum_to_string(Cat_breed cat){
    switch(cat){
        case Persian:
        return "retriever";
        case Russian:
        return "Russian";
        case Bengal:
        return "Bengal";
        case British:
        return "British";
        case Siamese:
        return "Siamese";
        case Sphynx:
        return "Sphynx";
        case Ragdoll:
        return "Ragdoll";
        case Birman:
        return "Birman";

        default:
        return "Invalid cat breed";

    }
}

// Constructor
Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age):
Animal{std::string name, Gender gender, int age}, _breed{breed}{}

// Destructor
~Cat::Cat(){}

// getter for family of the object
std::string Cat::family() override {
    return "cat";
}

// getter for breed of the object
std::string Cat::breed() override {
    return cat_enum_to_string(_breed);
}

// pure virtual method to convert the object into string
virtual std::string Cat::to_string(){
    std::string temp1;
    temp1 = static_cast<Animal>(*this).to_string()+" "+cat_enum_to_string(_breed);
    return temp1;
}

