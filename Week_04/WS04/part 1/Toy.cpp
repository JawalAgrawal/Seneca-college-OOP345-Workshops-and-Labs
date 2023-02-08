#include "Toy.h"

#include <iostream>
#include <iomanip>

namespace sdds {
    // Responsible for extracting information about the toy and storing the tokens in the instance's attributes
    Toy::Toy(const std::string& toy) {

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
        os << "Toy " << std::left << std::setw(8) << toy.t_orderID << ":";
        os << std::right << std::setw(18) << toy.t_name;
        os << std::left << std::setw(3) << toy.t_numberOfItems << "items";
        os << std::setw(8) << toy.t_price << "/item";
        os << std::setw(7) << "subtotal: " << t_subtotal;
        os << " tax: " << std::setw(6) << t_tax;
        os << " total: " << std::setw(7) << t_total << std::endl;
        return os;
    }
}