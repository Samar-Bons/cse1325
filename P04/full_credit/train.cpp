#include "train.h"
#include <cmath>

void Train::add_locomotive(Locomotive* locomotive){
    _locomotives.push_back(locomotive);
}

void Train::add_coach(Coach* coach){
    _coaches.push_back(coach);
}

double Train::speed(double minutes){
    double tempweight = 0.0;
    double temppower = 0.0;
    double seconds = 60*minutes;

    for(int i = 0; i < _locomotives.size(); i++){
        temppower += _locomotives[i]->power();
        tempweight += _locomotives[i]->weight();
    }
    for(int i = 0; i < _coaches.size(); i++){
        tempweight += _coaches[i]->weight();
    }

    return std::sqrt(2*temppower*seconds/tempweight);
}

std::string Train::to_art(){

    std::string output = "";

    for(int i = 0; i<6; i++){
        for(int j = 0; j < _locomotives.size(); j++){
            output += _locomotives[j]->ascii_art(i);
        }
        for(int k = 0; k < _coaches.size(); k++){
            output += _coaches[k]->ascii_art(i);
        }
        output += '\n';
    }
    return output;

}

