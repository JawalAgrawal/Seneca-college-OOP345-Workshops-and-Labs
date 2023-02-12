#include "ConfirmOrder.h"
#include <iostream>

namespace sdds {
    // Adds the toy to the array by adding its address
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        return *this;
    }

    // Rule of 5
    // Copy Semantics
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& src) {
        *this = src;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src) {
        if (this != &src) {
            co_toyCount = src.co_toyCount;

            // Dynamically allocating memory for the toys arrau
            toys = new const Toy*[src.co_toyCount];
            for (size_t i = 0; i < src.co_toyCount; i++) {
                toys[i] = src.toys[i];
            }
        }

        return *this;
    }

    // Move Semantics
    ConfirmOrder::ConfirmOrder(ConfirmOrder&& src) noexcept {
        *this = std::move(src);
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src) noexcept {
        if (this != &src) {
            co_toyCount = src.co_toyCount;

            // Dynamically allocating memory for the toys arrau
            toys = new const Toy*[src.co_toyCount];
            for (size_t i = 0; i < src.co_toyCount; i++) {
                toys[i] = src.toys[i];
            }

//            delete[] src.toys;
//            src.c_name = nullptr;
//            src.c_age = 0;
//            src.c_toyCount = 0;
//            src.toys = nullptr;
        }

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