/* Implementation of class Client */

#include "client.h"

// Constructor
Client::Client(std::string name, std::string phone, std::string email):
_name{name}, _phone{phone}, _email{email}{}

// Method to adopt an animal object
void Client::adopt(Animal& animal){
    adopted.push_back(animal);
}

// Getter method to obtain the number of animals adopted by the client
int Client::num_adopted(){
    return adopted.size();
}

// Getter method to return a specific animal adopted by the client using an index value
Animal& Client::animal(int index) const{
    return adopted[index];
}

