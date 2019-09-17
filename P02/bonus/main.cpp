//#include <iostream>
#include "average.h"
#include <cstdlib>
#include <vector>


int main(){

    std::vector<Average> students;
    students.push_back(Average());
    int student{0};


    std::srand(7404);//rand needs srand with a seed

    //object and variable initialization
    //Average avg;
    int choice{-1};//randomly assigned value to choice except 0,1,2,9

    //using a while loop for calculator 
    do{

        std::cout<<"\t=========================\n";
        std::cout<<"\tMerely Average Calculator\n";
        std::cout<<"\t=========================\n";

        std::cout<<"The current student is "<<student<<'\n';
        std::cout<<"The current average is "<<students[student]<<"\n\n";//to show the avg using
                                                          //the overloaded op. <<
        
        std::cout<<"1 - Enter a new value\n";
        std::cout<<"2 - Auto enter a random value\n";
        std::cout<<"5 - Create a new student\n";
        std::cout<<"6 - Select an existing student\n";
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
            std::cin>>students[student];

        }

        else if(choice == 2){
            //add random double between 0 and 100 to tot. avg.

           students[student].operator+=(100*((double)std::rand()/(double)RAND_MAX));
            
        }

        else if(choice == 5){
            //adding a student
            students.push_back(Average());
            student = students.size()-1;
            

        }
        else if(choice == 6){
            //Selecting an existing student
            std::cout<<"Select a student between (0 - "<<(students.size()-1)<<")\n";
            std::cin>>student;
            while(std::cin.fail()||((student<0)||(student>(students.size()-1)))){
                std::cout<<"Invalid command! Type again.\n";
                std::cin.clear();
                std::cin.ignore(32767,'\n');
                std::cin>>student;

            }
        }
        else if((choice!=1)&&(choice!=2)&&(choice!=9)&&(choice!=0)){
            //validating selections

            std::cout<<"Invalid selection!\n";
        }


    }
    while(choice!=0);

    return 0;
}