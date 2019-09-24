#include "coach.h"

Coach::Coach(double weight):Stock(weight){

    _art = { // Coach
            "               ",
            " ______________",
            " | [] [] [] []|",
            " |            |",
            "='OO--------OO'",
            "###############",
            };
}

void Coach::add_passengers(int passengers){

    _passengers = _passengers + passengers;
    //throw exception
}

double Coach::weight() {
    return Stock::weight() + ((double)_passengers*60);
}

