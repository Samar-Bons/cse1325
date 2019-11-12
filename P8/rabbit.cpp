#include "rabbit.h"

std::string rabbit_enum_to_string(Rabbit_breed rabbit){
    switch(rabbit){
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
        return "Invalid Rabbit breed";

    }
}

Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age):
Animal{std::string name, Gender gender, int age}, _breed{breed}{}

~Rabbit::Rabbit(){}

std::string Rabbit::family() override {
    return "Rabbit";
}

std::string Rabbit::breed() override {
    return rabbit_enum_to_string(_breed);
}

virtual std::string Rabbit::to_string(){
    std::string temp1;
    temp1 = static_cast<Animal>(*this).to_string()+" "+rabbit_enum_to_string(_breed);
    return temp1;
}

