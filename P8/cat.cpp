#include "cat.h"

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

Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age):
Animal{std::string name, Gender gender, int age}, _breed{breed}{}

~Cat::Cat(){}

std::string Cat::family() override {
    return "cat";
}

std::string Cat::breed() override {
    return cat_enum_to_string(_breed);
}

virtual std::string Cat::to_string(){
    std::string temp1;
    temp1 = static_cast<Animal>(*this).to_string()+" "+cat_enum_to_string(_breed);
    return temp1;
}

