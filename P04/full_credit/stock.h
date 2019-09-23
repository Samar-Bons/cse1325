#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <string>
#include <cmath>

class Stock{
    double _weight;

    protected:
    std::vector<std::string> _art;

    public:
    Stock();

    Stock(double weight);

    virtual double weight();

    std::string ascii_art(int row);
}

#endif
