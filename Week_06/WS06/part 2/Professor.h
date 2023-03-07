#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include "Employee.h"
#include <iostream>

namespace sdds {
    class Professor : public Employee {
    private:
        std::string m_department {};
    public:
        Professor() = default;
        // Calls the constructor from Employee to build the sub-object
        Professor(std::istream& in);
        // Calls Employee::display() to print the information about the Employee, and adds department|"Professor" at the end
        void display(std::ostream& out) const;
        // A query that returns word Professor
        std::string status() const;
        // A query that returns the department
        std::string department() const;
    };
}

#endif // SDDS_PROFESSOR_H