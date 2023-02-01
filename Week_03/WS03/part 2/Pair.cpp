/*
*****************************************************************************
                              Pair.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 01 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Pair.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds {
    Pair::Pair() {};

    // Display Function
    std::ostream& Pair::display(std::ostream& os) const {
        os << setw(20) << right << m_key << ": " << left << m_value;
        return os;
    }

    // Insertion operator overload
    std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        return pair.display(os);
    }
}