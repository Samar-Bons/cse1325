#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H

#include "stock.h"

class Locomotive : public Stock {
    double _power;

    public:
    Locomotive(double weight = 80000, double power = 13500);

    double power();
}

#endif

