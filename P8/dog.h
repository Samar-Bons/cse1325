/* Header for clas Dog */

#ifndef __DOG_H
#define __DOG_H

#include <string>

// enumerating the dog breeds the shelter deals with
enum class Dog_breed{retriever, pug, frenchie, english, mastiff, pitbull, shepherd, collie};

// declaring class Dog
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
