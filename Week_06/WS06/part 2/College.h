#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

#include "Person.h"
#include <iostream>
#include <vector>

namespace sdds {
    class College {
    private:
        std::vector<Person*> m_persons {};
    public:
        College() = default;
        // Disabling copy operations
        College(const College&) = delete;
        College& operator=(const College&) = delete;
        // Adds the address of the person object received as parameter into the m_persons vector
        College& operator +=(Person* thePerson);
        // Iterates over the persons stored in m_persons and prints their details
        void display(std::ostream& out = std::cout) const;
    };
}

#endif // SDDS_COLLEGE_H