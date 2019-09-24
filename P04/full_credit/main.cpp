#include "stock.h"
#include "coach.h"
#include "locomotive.h"
#include "train.h"
#include <iostream>
#include <iomanip>

int main(){

    Train train;
    int command{-1};

    while(command!=0){
        std::cout<<"\t\t\t========================\n";
        std::cout<<"\t\t\t  The CSE1325 Express   \n";
        std::cout<<"\t\t\t========================\n";

        std::cout<<train.to_art();

        std::cout<<std::setw(10)<<" Minutes |"<<std::setw(10)<<"1    "<<std::setw(10)<<"5    "<<std::setw(10)<<"15    "<<std::setw(10)<<"30    "<<std::setw(10)<<"60    ";
        std::cout<<'\n';
        std::cout<<std::setw(10)<<"---------|"<<std::setw(10)<<"---------|"<<std::setw(10)<<"---------|"<<std::setw(10)<<"---------|"<<std::setw(10)<<"---------|"<<std::setw(10)<<"---------|";
        std::cout<<'\n';
        std::cout<<std::setw(10)<<"m/s    |"<<std::setw(9)<<std::setprecision(2)<<train.speed(1)<<"|"<<std::setw(9)<<std::setprecision(2)<<train.speed(5)<<"|"<<std::setw(9)<<std::setprecision(2)<<train.speed(15)<<"|"<<std::setw(9)<<std::setprecision(2)<<train.speed(30)<<"|"<<std::setw(9)<<std::setprecision(2)<<train.speed(60);
        std::cout<<'\n';

        std::cout<<"1 - Add a locomotive\n";
        std::cout<<"2 - Add an empty coach\n";
        std::cout<<"9 - Clear the train\n";
        std::cout<<"0 - Exit\n\n";
        std::cout<<"Command?\n";

        std::cin>>command;
        while((std::cin.fail())||((command!=0)&&(command!=1)&&(command!=9)&&(command!=2))){
            
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"Wrong command. Select again\n";

            std::cin>>command;
        }

        if(command == 1){
            //Locomotive loco;
            //Locomotive *ptr = &loco;
            train.add_locomotive(new Locomotive());
        }
        else if (command == 2){
            //Coach coco;
            train.add_coach(new Coach());

        }
        else if (command == 9){
            train = Train();
        }


    }
}