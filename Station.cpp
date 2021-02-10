//
// Created by Beyza on 6.12.2020.
//

#include "Station.h"

Station::Station() {}

Station::Station(std::string city) { stationName = city; }

Station::~Station() {}

std::string Station::getCity() { return stationName; }

