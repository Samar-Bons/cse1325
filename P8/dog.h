#ifndef __DOG_H
#define __DOG_H

#include <string>

enum class Dog_breed{retriever, pug, frenchie, english, mastiff, pitbull, shepherd, collie};

class Dog: public Animal
{
    private:
    Dog_breed _breed;
    
    public:
    Dog(Dog_breed breed, std::string name, Gender gender, int age);
    ~Dog();
    std::string family();
    std::string breed();
    std::string to_string();


};

#endif
