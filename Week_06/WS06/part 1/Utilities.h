#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Person.h"
#include <iostream>

namespace sdds {
    // Creates instances on the Person hierarchy
    Person* buildInstance(std::istream& in);
}

#endif // SDDS_UTILITIES_H