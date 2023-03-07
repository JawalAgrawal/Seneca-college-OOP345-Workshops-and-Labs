#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

namespace sdds {
    // Read a single record from the stream, extract all the information about a single student and store it in the attributes
    Student::Student(std::istream& is) {

    }

    // A query that returns the string Student
    std::string Student::status() const { return "Student"; }

    // A query that returns the name of the student
    std::string Student::name() const { return m_name; }

    // A query that inserts in the first parameter the content of the student object
    void Student::display(std::ostream& out = std::cout) const {

    }
}