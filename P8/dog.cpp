#include "dog.h"

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

Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age):
Animal{std::string name, Gender gender, int age}, _breed{breed}{}

~Dog::Dog(){}

std::string Dog::family() override {
    return "dog";
}

std::string Dog::breed() override {
    return dog_enum_to_string(_breed);
}

virtual std::string Dog::to_string(){
    std::string temp1;
    temp1 = static_cast<Animal>(*this).to_string()+" "+dog_enum_to_string(_breed);
    return temp1;
}


