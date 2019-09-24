#ifndef TRAIN_H
#define TRAIN_H

#include "coach.h"
#include "locomotive.h"
//#include <vector>


class Train{
    std::vector<Locomotive*> _locomotives;
    std::vector<Coach*> _coaches;

    public:
    void add_locomotive(Locomotive* locomotive);

    void add_coach(Coach* coach);

    double speed(double minutes);

    std::string to_art();

};

#endif
