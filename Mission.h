//
// Created by Beyza on 6.12.2020.
//

#ifndef ASSIGNMENT3_MISSION_H
#define ASSIGNMENT3_MISSION_H

#include "Station.h"
#include <fstream>
#include <vector>
#include <sstream>

class Mission{
public:
    // constructors and destructors
    Mission();
    Mission(const std::string& destinations, const std::string& packageFile, const std::string& truckFile,
            const std::string& missionFile, const std::string& result);
    ~Mission();

    // fstream objects for reading input files and writing to output file
    std::fstream dest;
    std::fstream pack;
    std::fstream trucks;
    std::fstream miss;
    std::fstream output;

    std::vector<std::string> command; // vector for storing lines of inputs
    std::vector<Station> stations; // vector for storing stations
};

#endif //ASSIGNMENT3_MISSION_H
