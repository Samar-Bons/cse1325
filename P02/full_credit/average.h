#ifndef AVERAGE_H
#define AVERAGE_H

class Average{
    double _sum;
    int _values;

    public:

    Average();

    friend std::ostream& operator<<(ostream& ost, const Average& average);

    friend std::istream& operator>>(istream& ist, Average& average);

    Average& operator+=(double value);

};

#endif
