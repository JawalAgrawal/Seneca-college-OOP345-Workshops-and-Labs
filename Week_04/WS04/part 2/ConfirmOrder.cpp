#include "ConfirmOrder.h"
#include <iostream>

namespace sdds {
    // Adds the toy to the array by adding its address
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        return *this;
    }

    // Removes the toy from the array by removing its address
    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        return *this;
    }

    // Insert the content of a ConfirmOrder object into an ostream object
    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirmOrder) {
            os << "--------------------------" << std::endl;
            os << "Confirmations to Send" << std::endl;
            os << "--------------------------" << std::endl;

            if (confirmOrder.co_toyCount == 0) {
                os << "There are no confirmations to send!" << std::endl;
            } else {
                for (int i = 0; i < confirmOrder.co_toyCount; i++) {
                    os << *confirmOrder.toys[i] << std::endl;
                }
            }
            os << "--------------------------\n";

            return os;
    }
}