#ifndef AVERAGE_H
#define AVERAGE_H

class Average{
    double _sum;
    int _values;

    public:

    Average();

    friend std::ostream& operator<<(ostream& ost, const Average& average);

    friend std::istream& operator>>(istream& ist, const Average& average);

    Average& operator+=(double value);

};

#endif
