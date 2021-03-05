/* Implementing class Dog */

#include "dog.h"

// method to convert enum breed to string
std::string dog_enum_to_string(Dog_breed dog){
    switch(dog){
        case retriever:
        return "retriever";
        case pug:
        return "pug";
        case frenchie:
        return "frenchie";
        case english:
        return "english";
        case mastiff:
        return "mastiff";
        case pitbull:
        return "pitbull";
        case shepherd:
        return "shepherd";
        case collie:
        return "collie";

        default:
        return "Invalid dog breed";

    }
}

// Constructor
Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age):
Animal{std::string name, Gender gender, int age}, _breed{breed}{}

// Destructor
~Dog::Dog(){}

// getter for family of the object
std::string Dog::family() override {
    return "dog";
}

// getter for breed of the object
std::string Dog::breed() override {
    return dog_enum_to_string(_breed);
}

// pure virtual method to convert the object into string
virtual std::string Dog::to_string(){
    std::string temp1;
    temp1 = static_cast<Animal>(*this).to_string()+" "+dog_enum_to_string(_breed);
    return temp1;
}


