#include "coach.h"

Coach::Coach(double weight = 28000):Stock(weight){}

void Coach::add_passengers(int passengers){

    _passengers = _passengers + passengers;
    //throw exception
}

double Coach::weight() override {
    return Stock::weight() + (_passengers*60);
}

