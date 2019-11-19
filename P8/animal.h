#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>
#include <string>

enum class Gender{M,F};

class Animal{
    protected:
    std::string _name;
    Gender _gender;
    int _age;

    public:
    Animal(std::string name, Gender gender, int age);
    ~Animal();
    virtual std::string family() = 0;
    virtual std::string breed() = 0;
    std::string name();
    Gender gender();
    int age();
    virtual std::string to_string();
   
};

#endif
