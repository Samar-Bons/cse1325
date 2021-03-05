/* Header for Shelter class */

#ifndef __SHELTER_H
#define __SHELTER_H

#include <string>
#include <vector>

class Shelter
{
    private:

    // Every Shelter has a name, a list of Animals and a list of Clients
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client> _clients;

    public:

    // Public methods 
    Shelter(std::string name);
    std::string name();
    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index);
    void add_client(Client &client);
    int num_clients();
    Client& client(int index);
    void adopt(Client& client, Animal& animal);
    
    

    
};

#endif
