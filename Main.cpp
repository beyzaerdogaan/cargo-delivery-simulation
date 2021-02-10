#include <iostream>
#include "Mission.h"

int main(int argc, char **argv) {
    try {
        Mission* mission = new Mission(argv[1], argv[2], argv[3], argv[4], argv[5]);
    }
    catch (const char *error) {
        // catch if stackException or queueException occurs and write it to file
        std::fstream output;
        output.open(argv[5], std::ios::out);
        output << error << std::endl;
    }
    return 0;
}
