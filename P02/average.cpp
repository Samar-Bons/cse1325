#include "average.h"
#include <iostream>

Average::Average():_sum{0},_values{0}{}

std::ostream& operator<<(ostream& ost, const Average& average){
    if(average._values!=0){
        ost<<average._sum/average._values;
        return ost;
    }
    else
    {
        ost<<"undefined";
        return ost;
    }

}

std::istream& operator>>(istream& ist, Average& average){
    double temp;
    ist>>temp;
    average._sum += temp;
    average._values += 1;
    return ist;

}

Average& Average::operator+=(double value){
    _sum += value;
    _values += 1;
    
}
