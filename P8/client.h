#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>

class Client{
    private: 
    std::string _name;
    std::string _phone;
    std::string _email;

    public:
    Client(std::string name, std::string phone, std::string email);

}

#endif
