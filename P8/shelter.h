#ifndef __SHELTER_H
#define __SHELTER_H

#include <string>
#include <vector>

class Shelter
{
    private:
    std::string _name;
    std::vector<Animal*> _available;

    public:
    Shelter(std::string name);
    std::string name();
    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index);
    
};

#endif
