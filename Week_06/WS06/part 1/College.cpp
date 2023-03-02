#include "College.h"
#include <iostream>

namespace sdds {
    // Adds the address of the person object received as parameter into the m_persons vector
    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    // Iterates over the persons stored in m_persons and prints their details
    void College::display(std::ostream& out) const {
        std::vector<Person*>::iterator i {};
        for (i = m_persons.begin(); i != m_persons.end(); i++)
            out << *i << "  ";
    }
}