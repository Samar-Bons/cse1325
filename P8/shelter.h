#ifndef __SHELTER_H
#define __SHELTER_H

#include <string>
#include <vector>

class Shelter
{
    private:
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client> _clients;

    public:
    Shelter(std::string name);
    std::string name();
    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index);
    void add_client(Client &client);
    int num_clients();
    Client& client(int index);
    

    
};

#endif
