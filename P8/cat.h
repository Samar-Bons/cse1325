/* Header for class Cat */

#ifndef __CAT_H
#define __CAT_H

#include <string>

// enumerating the cat breeds the shelter deals with
enum class Cat_breed{Persian, Russian, Bengal, British, Siamese, Sphynx, Ragdoll, Birman};

// declaring class Cat
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
