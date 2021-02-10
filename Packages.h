//
// Created by Beyza on 6.12.2020.
//

#ifndef ASSIGNMENT3_PACKAGES_H
#define ASSIGNMENT3_PACKAGES_H

#include <string>

class Packages {
public:
    // constructors
    Packages();
    Packages(std::string ids);
    // destructor
    ~Packages();

    // get the id of package
    std::string getId();

protected:
    std::string id;
};

#endif //ASSIGNMENT3_PACKAGES_H
