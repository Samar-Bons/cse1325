#include "client.h"

Client::Client(std::string name, std::string phone, std::string email):
_name{name}, _phone{phone}, _email{email}{}

void Client::adopt(Animal& animal){
    adopted.push_back(animal);
}

int Client::num_adopted(){
    return adopted.size();
}

Animal& Client::animal(int index) const{
    return adopted[index];
}

