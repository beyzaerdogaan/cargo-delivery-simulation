//
// Created by Beyza on 6.12.2020.
//

#ifndef ASSIGNMENT3_TRUCK_H
#define ASSIGNMENT3_TRUCK_H

#include "Packages.h"

class Truck : public Packages {
public:
    Truck(std::string ids, std::string pwr);
    Truck();
private:
    std::string power;
};

#endif //ASSIGNMENT3_TRUCK_H
