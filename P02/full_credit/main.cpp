//#include <iostream>
#include "average.h"
#include <cstdlib>

int main(){

    
    std::srand(7404);//rand needs srand with a seed

    //object and variable initialization
    Average avg;
    int choice{-1};//randomly assigned value to choice except 0,1,2,9

    //using a while loop for calculator 
    do{

        std::cout<<"\t=========================\n";
        std::cout<<"\tMerely Average Calculator\n";
        std::cout<<"\t=========================\n";

        std::cout<<"The current average is "<<avg<<"\n\n";//to show the avg using
                                                          //the overloaded op. <<
        
        std::cout<<"1 - Enter a new value\n";
        std::cout<<"2 - Auto enter a random value\n";
        std::cout<<"9 - Clear the calculator\n";
        std::cout<<"0 - Exit\n\n";
        std::cout<<"Command?\n";

        std::cin>>choice;//to take in the command

        while(std::cin.fail()){
            std::cout<<"Invalid command. Try again- \n";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cin>>choice;
        }

        //if statements for each case

        if(choice == 1){
            //add user given double value to total average

            std::cout<<"Value?\n";
            std::cin>>avg;

        }

        else if(choice == 2){
            //add random double between 0 and 100 to tot. avg.

           avg.operator+=(100*((double)std::rand()/(double)RAND_MAX));
            
        }

        else if(choice == 9){
            //resetting the avg. to undefined (_values and _sum must be 0)
            avg = Average();

        }
        else if((choice!=1)&&(choice!=2)&&(choice!=9)&&(choice!=0)){
            //validating selections

            std::cout<<"Invalid selection!\n";
        }


    }
    while(choice!=0);

    return 0;
}