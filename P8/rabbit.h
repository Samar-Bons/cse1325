#ifndef __RABBIT_H
#define __RABBIT_H

#include <string>

enum class Rabbit_breed{American, Belgian, Californian, Dutch, Angora, Harlequin, Lionhead, Tan};

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
