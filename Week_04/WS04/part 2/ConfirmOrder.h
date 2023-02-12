/*
*****************************************************************************
                              ConfirmOrder.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H

#include <iostream>
#include "Toy.h"

namespace sdds {
    class ConfirmOrder {
    private:
        const sdds::Toy** toys { nullptr };
        size_t co_toyCount { 0 };
    public:
        // Default Constructor
        ConfirmOrder() = default;

        // Rule of 5
        // Copy Semantics
        ConfirmOrder(const ConfirmOrder& src);
        ConfirmOrder& operator=(const ConfirmOrder& src);

        // Move Semantics
        ConfirmOrder(ConfirmOrder&& src) noexcept;
        ConfirmOrder& operator=(ConfirmOrder&& src) noexcept;

        // Adds the toy to the array by adding its address
        ConfirmOrder& operator+=(const Toy& toy);

        // Removes the toy from the array by removing its address
        ConfirmOrder& operator-=(const Toy& toy);

        // Insert the content of a ConfirmOrder object into an ostream object
        friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirmOrder);
    };
}

#endif // SDDS_CONFIRMORDER_H