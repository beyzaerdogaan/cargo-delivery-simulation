//
// Created by Beyza on 8.12.2020.
//

#include "Packages.h"
Packages::Packages() {}

Packages::Packages(std::string ids) { this->id = ids; }

Packages::~Packages() {}

std::string Packages::getId() { return id; }