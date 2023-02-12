/*
*****************************************************************************
                              Toy.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Toy.h"

#include <iostream>
#include <iomanip>

namespace sdds {
    // Responsible for extracting information about the toy and storing the tokens in the instance's attributes
    Toy::Toy(const std::string& toy) {
        // Initializing the start and the end index
        size_t startIndex = 0;
        size_t endIndex = toy.find(':');

        // Storing the ID
        t_orderID = std::stoi(toy.substr(startIndex, (endIndex - startIndex)));
        startIndex = endIndex + 1;
        endIndex = toy.find(':', startIndex);

        // Storing the name
        t_name = toy.substr(startIndex, (endIndex - startIndex));

        // Erasing trailing and leading white spaces
        t_name.erase(0, t_name.find_first_not_of(" \t\r\n"));
        t_name.erase(t_name.find_last_not_of(" \t\r\n") + 1);

        startIndex = endIndex + 1;
        endIndex = toy.find(':', startIndex);

        // Storing the number of items
        t_numberOfItems = std::stoi(toy.substr(startIndex, (endIndex - startIndex)));
        startIndex = endIndex + 1;
        endIndex = toy.find(':', startIndex);

        // Storing the price
        t_price = std::stod(toy.substr(startIndex, (endIndex - startIndex)));
    }

    // Updates the number of items attribute with the received value
    void Toy::update(int numItems) {
        t_numberOfItems = numItems;
    }

    // Insert the contents of a toy object into an ostream object
    std::ostream& operator<<(std::ostream& os, const Toy& toy) {
        // Calculations
        double t_subtotal = toy.t_price * toy.t_numberOfItems;
        double t_tax = t_subtotal * (toy.t_hstPercentage / 100);
        double t_total = t_subtotal + t_tax;

        // Inserting into output stream
        os << "Toy" << std::right << std::setw(8) << toy.t_orderID << ":";
        os << std::right << std::setw(18) << toy.t_name;
        os << std::right << std::setw(3) << toy.t_numberOfItems << " items";
        os << std::setw(8) << toy.t_price << "/item";
        os << "  subtotal:";
        os << std::right  << std::setw(7) << std::fixed << std::setprecision(2) << t_subtotal;
        os << std::right  << " tax:" << std::setw(6) << t_tax;
        os << std::right  << " total:" << std::setw(7) << t_total << std::endl;
        return os;
    }
}