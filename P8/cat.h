#ifndef __CAT_H
#define __CAT_H

#include <string>

enum class Cat_breed{Persian, Russian, Bengal, British, Siamese, Sphynx, Ragdoll, Birman};

class Cat: public Animal
{
    private:
    Cat_breed _breed;
    
    public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    ~Cat();
    std::string family();
    std::string breed();
    std::string to_string();


};

#endif
