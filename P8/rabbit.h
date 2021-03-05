/* Header file for class Rabbit */

#ifndef __RABBIT_H
#define __RABBIT_H

#include <string>

// enumerating the breeds of rabbits the shelter deals with

enum class Rabbit_breed{American, Belgian, Californian, Dutch, Angora, Harlequin, Lionhead, Tan};

// declaring class Rabbit

class Rabbit: public Animal
{
    private:
    Rabbit_breed _breed;
    
    public:
    Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
    ~Rabbit();
    std::string family();
    std::string breed();
    std::string to_string();


};

#endif
