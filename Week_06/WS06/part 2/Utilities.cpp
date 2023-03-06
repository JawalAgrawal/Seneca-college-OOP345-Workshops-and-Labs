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
        }

        // Ignoring the rest of the string
        in.ignore(1000, '\n');
        return nullptr;
    }
}