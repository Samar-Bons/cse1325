#include "animal.h"

std::string enum_to_string(Gender gender){
    switch(gender){
        case M:
        return "M";
        case F:
        return "F";
        default:
        return "invalid Gender";
    }
}

Animal::Animal(std::string name, Gender gender, int age):
_name{name}, _gender{gender}, _age{age}{}

~Animal::Animal(){}

std::string Animal::name(){
    return _name;
}

Gender Animal::gender(){
    return _gender;
}

int Animal::age(){
    return _age;
}

virtual std::string Animal::to_string(){
    std::string temp;
    temp = _name+" "+enum_to_string(_gender)+" "+std::to_string(_age)+"/n";
    return temp;
}

friend std::ostream& Animal::operator<<(std::ostream& ost, const Animal& animal){
    ost<<animal.to_string();
    return ost;
}


