/* Header for class Client */

#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>
#include <vector>

// Declaring class Client
// A client will have a name, a phone number, email and a list of adopted Animals  
class Client{
    private: 
    std::string _name;
    std::string _phone;
    std::string _email;
    std::vector<Animal*> adopted;

    
    public:
    Client(std::string name, std::string phone, std::string email);
    void adopt(Animal& animal);
    int num_adopted();
    Animal& animal(int index) const;

    // The operator << is overloaded and used as a friend function to print the client name
    friend std::ostream& operator<<(std::ostream& ost, const Client& client){
        ost << client._name+"\n";
        return ost;
    }
    

}

#endif
