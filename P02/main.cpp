#include "average.h"
#include <iostream>

int main(){

    Average avg();
    int choice{-1};

    while(choice!=0){

        std::cout<<"\t=========================\n";
        std::cout<<"\tMerely Average Calculator\n";
        std::cout<<"\t=========================\n";

        std::cout<<"The current average is "<<avg<<"\n\n";

        std::cout<<"1 - Enter a new value\n";
        std::cout<<"2 - Auto enter a random value\n";
        std::cout<<"9 - Clear the calculator\n";
        std::cout<<"0 - Exit\n\n";
        std::cout<<"Command?\n";

        std::cin>>choice;

        


    }

    return 0;
}