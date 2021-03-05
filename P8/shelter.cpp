#include "shelter.h"
// class Shelter implementation

// constructor 
Shelter::Shelter(std::string name):
_name{name}{}

// getter method for the name of the shelter
std::string Shelter::name(){
    return _name;
}

// method to add object animal to the shelter object's vector _available
void Shelter::add_animal(Animal& animal){
    _available.push_back(animal);
}

// getter method for the size of vector _available
int Shelter::num_animals(){
    return _available.size();
}

// getter for specific animal object in _available
Animal& Shelter::animal(int index){
    return _available[index];
}

// method to add Client object to _clients vector 
void Shelter::add_client(Client& client){
    _clients.push_back(client);
}

// getter for size of _clients vector
int Shelter::num_clients(){
    return _clients.size();
}

// getter for size _clients
Client& Shelter::client(int index){
    return _clients[index];
}

// method to adopt an available animal in the shelter by a client
// It will remove the animal from _available and call the client.adopt() method
void Shelter::adopt(Client& client, Animal& animal){
    _available.erase(animal);
    client.adopt(animal);
}