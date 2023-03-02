#include "Utilities.h"
#include "Employee.h"
#include <iostream>

namespace sdds {
    // Creates instances on the Person hierarchy
    Person* buildInstance(std::istream& in) {
        char tag {};
        in >> tag;

        if (tag == 'e' || tag == 'E') {
            return new Employee(in);
        } else {
            // Clearing the string
            std::string flush;
            getline(in, flush);
        }
        return nullptr;
    }
}