//
// Created by Beyza on 6.12.2020.
//

#ifndef ASSIGNMENT3_STATION_H
#define ASSIGNMENT3_STATION_H

#include <string>
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkedList.h"
#include "Truck.h"

class Station {
public:
    // constructors and destructors
    Station();
    Station(std::string city);
    ~Station();

    // initialize data structures that we need for transportation and storing packages and trucks
    Stack<Packages>* packages = new Stack<Packages>;
    Queue<Truck>* garage = new Queue<Truck>;

    // get the station name
    std::string getCity();

private:
    std::string stationName;
};

#endif //ASSIGNMENT3_STATION_H
