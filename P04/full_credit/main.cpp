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

        std::cout<<setw(10)<<" Minutes |"<<setw(10)<<"1    "<<setw(10)<<"5    "<<setw(10)<<"15    "<<setw(10)<<"30    "<<setw(10)<<"60    ";
        std::cout<<'\n';
        std::cout<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|";
        std::cout<<'\n';
        std::cout<<setw(10)<<"m/s    |"<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|"<<setw(10)<<"---------|";
    }
}