#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>
#include <vector>

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
    friend std::ostream& operator<<(std::ostream& ost, const Client& client){
        ost << client._name+"\n";
        return ost
    }
    

}

#endif
