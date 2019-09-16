#ifndef AVERAGE_H
#define AVERAGE_H

#include <iostream>


//class declaration
class Average{
    double _sum;
    int _values;

    public:

    Average();

    friend std::ostream& operator<<(std::ostream& ost, Average& average);

    friend std::istream& operator>>(std::istream& ist, Average& average);

    Average& operator+=(double value);

};

#endif
