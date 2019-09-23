#ifndef COACH_H
#define COACH_H

#include "stock.h"

class Coach: public Stock {
    int _passengers;

    public:
    Coach(double weight = 28000);

    void add_passengers(int passengers);

    double weight();

}

#endif

    