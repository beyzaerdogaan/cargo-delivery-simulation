//
// Created by Beyza on 6.12.2020.
//

#include <algorithm>
#include "Mission.h"

Mission::Mission() {}

Mission::Mission(const std::string& destinations, const std::string& packageFile, const std::string& truckFile,
                 const std::string& missionFile, const std::string& result)
{
    std::string line;

    // read dest file
    dest.open(destinations, std::ios::in);
    while (getline(dest, line))
    {
        Station* station = new Station(line);
        stations.push_back(*station); // store all of the possible stations
    }
    dest.close();

    // read packages file
    pack.open(packageFile, std::ios::in);
    while (getline(pack, line))
    {
        std::stringstream ss(line);
        std::string item;
        while(getline(ss, item, ' ')) {
            command.push_back(item); // store command
        }
        Packages* package = new Packages(command[0]); // create new package object with the given id
        for (int i = 0; i < stations.size(); i++)
        {
            if (stations[i].getCity() == command[1])
            {
                // store the package object that we created into the station where it belongs
                stations[i].packages->push(*package);
            }
        }
        command.clear(); // clear the command vector so that it can be available for the next line
    }
    pack.close();

    // read truck file
    trucks.open(truckFile, std::ios::in);
    while (getline(trucks, line))
    {
        std::stringstream ss(line);
        std::string item;
        while(getline(ss, item, ' ')) {
            command.push_back(item); // store command
        }
        // create new truck object with the given id and power information
        Truck* truck = new Truck(command[0], command[2]);
        for (int i = 0; i < stations.size(); i++)
        {
            if (stations[i].getCity() == command[1])
            {
                // store the truck object that we created into the station where it belongs
                stations[i].garage->enqueue(*truck);
            }
        }
        command.clear(); // clear the command vector so that it can be available for the next line
    }
    trucks.close();

    // read mission file
    miss.open(missionFile, std::ios::in);
    while (getline(miss, line))
    {
        std::stringstream ss(line);
        std::string item;
        while(getline(ss, item, '-')) {
            command.push_back(item); // store command
        }

        std::stringstream ss1(command[5]);
        std::string index;
        std::vector<int> packageIndexes;
        while(getline(ss1, index, ',')) {
            // store the package indexes of the packages that we are going to leave at the midway station
            packageIndexes.push_back(stoi(index));
        }

        Station* startingStation = new Station;
        Station* midwayStation = new Station;
        Station* targetStation = new Station;
        for (int i = 0; i < stations.size(); i++)
        {
            /* find starting station, midway station and target station in stations vector and store them
              into specific station objects that we defined for completing the mission */
            if (stations[i].getCity() == command[0])
            {
                startingStation = &stations[i];
            }
            if (stations[i].getCity() == command[1])
            {
                midwayStation = &stations[i];
            }
            if (stations[i].getCity() == command[2])
            {
                targetStation = &stations[i];
            }
        }

        // check if there is a non-existing station
        if (startingStation->getCity().empty())
        {
            return;
        }
        if (midwayStation->getCity().empty())
        {
            return;
        }
        if (targetStation->getCity().empty())
        {
            return;
        }

        DoublyLinkedList<Packages>* transport = new DoublyLinkedList<Packages>; // initialize transport list

        Truck* truck = new Truck; // create new truck object
        startingStation->garage->getFront(*truck); // get the first truck in the garage
        transport->insert(*truck); // insert the truck in transport list
        startingStation->garage->dequeue(); // remove the truck from the garage
        for (int j = 0; j < stoi(command[3]); j++)
        {
            // take packages from the starting station as many as wanted and upload them in transport list
            Packages* package = new Packages;
            startingStation->packages->getTop(*package);
            transport->insert(*package);
            startingStation->packages->pop();
        }

        for (int j = 0; j < stoi(command[4]); j++)
        {
            // take packages from the midway station as many as wanted and upload them to the transport list
            Packages* package = new Packages;
            midwayStation->packages->getTop(*package);
            transport->insert(*package);
            midwayStation->packages->pop();
        }

        for (int k = 0; k < packageIndexes.size(); k++)
        {
            // insert the packages that have the given indexes to the midway station
            Packages* insertPackage = new Packages;
            transport->getItem(*insertPackage, packageIndexes[k]);
            midwayStation->packages->push(*insertPackage);
        }

        for (int k = 0; k < packageIndexes.size(); k++)
        {
            /* remove the packages that we dropped in the midway station from the transport list. first we
              sort the package indexes in decreasing order so that the indexes of the other objects do
              not shift */
            std::sort(packageIndexes.rbegin(), packageIndexes.rend());
            transport->remove(packageIndexes[k]);
        }

        for (int k = 0; k < transport->size()-1; k++) {
            // leave all the packages in the transport list to the target station
            Packages *package = new Packages;
            transport->getItem(*package, k);
            targetStation->packages->push(*package);
        }
        // leave the truck to the target station
        Truck* finalTruck = new Truck;
        transport->getItem(*finalTruck, -1);
        targetStation->garage->enqueue(*finalTruck);
        transport->deleteAll();

        packageIndexes.clear(); // clear the package index vector so that it can be available for the next line
        command.clear(); // clear the command vector so that it can be available for the next line
    }
    miss.close();

    output.open(result, std::ios::out);
    // write final situation of stations to the output file
    for (int l = 0; l < stations.size(); l++)
    {
        output << stations[l].getCity() << std::endl;
        output << "Packages:" << std::endl;
        Packages* displayPackage = new Packages;
        int sizeOfPackages = stations[l].packages->size();
        for (int m = 0; m < sizeOfPackages; m++)
        {
            stations[l].packages->getTop(*displayPackage);
            output << displayPackage->getId() << std::endl;
            stations[l].packages->pop();
        }
        Truck* displayTruck = new Truck;
        int sizeOfTrucks = stations[l].garage->size();
        output << "Trucks:" << std::endl;
        for (int m = 0; m < sizeOfTrucks; m++)
        {
            stations[l].garage->getFront(*displayTruck);
            output << displayTruck->getId() << std::endl;
            stations[l].garage->dequeue();
        }
        output << "-------------" << std::endl;
    }
    output.close();
}

Mission::~Mission() {}
