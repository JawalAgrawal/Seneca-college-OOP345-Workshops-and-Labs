/*
*****************************************************************************
                              ConfirmOrder.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "ConfirmOrder.h"
#include <iostream>

namespace sdds {
    // Rule of 5
    // Copy Semantics
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& src) {
        *this = src;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src) {
        if (this != &src) {
            // Deleting the dynamically allocated memory
            if (toys) {
                delete[] toys;
                toys = nullptr;
            }

            co_toyCount = src.co_toyCount;

            // Dynamically allocating memory for the toys arrau
            toys = new const Toy*[src.co_toyCount];

            // Assignment
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
            // Deleting the dynamically allocated memory
            if (toys) {
                delete[] toys;
                toys = nullptr;
            }

            co_toyCount = src.co_toyCount;

            // Dynamically allocating memory for the toys arrau
            toys = new const Toy*[src.co_toyCount];

            // Assignment
            for (size_t i = 0; i < src.co_toyCount; i++) {
                toys[i] = src.toys[i];
            }
        }

        return *this;
    }

    // Destructor
    ConfirmOrder::~ConfirmOrder() {
        delete[] toys;
    }

    // Adds the toy to the array by adding its address
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        // If the address of the toy is already in the array, the operator does nothing
        bool toyExists = false;
        for (size_t i = 0; i < co_toyCount; i++) {
            if (toys[i] == &toy) {
                toyExists = true;
                break;
            }
        }

        if (!toyExists) {
            // Creating a temporary array and making changes to it
                const Toy** tempToyArr = new const Toy*[co_toyCount + 1];
                // Copying all items from the original array to the temporary array
                for (size_t i = 0; i < co_toyCount; i++) {
                    tempToyArr[i] = toys[i];
                }

                // Adding the new item to the temporary array
                tempToyArr[co_toyCount] = &toy;
                co_toyCount++;

                // Deleting the original array and assigning the temp array to the original array
                delete[] toys;
                toys = tempToyArr;
        }

        return *this;
    }

    // Removes the toy from the array by removing its address
    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        // Check if the toy is in the array
        bool toyExists = false;
        size_t indexFound = -1;
        for (size_t i = 0; i < co_toyCount; i++) {
            if (toys[i] == &toy) {
                toyExists = true;
                indexFound = i;
                break;
            }
        }

        // Removing the toy address
        if (toyExists) {
            const Toy** tempToyArr = new const Toy*[co_toyCount - 1];
            size_t origIndex { 0 };

            for (size_t i = 0; i < co_toyCount; i++) {
                // Removing the item from the temporary array
                if (i != indexFound) {
                    tempToyArr[origIndex] = toys[i];
                    origIndex++;
                }
            }

            // Deleting the original array and assigning the temporary array to the original one
            co_toyCount--;
            delete[] toys;
            toys = tempToyArr;
        }

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
                for(size_t i = 0; i < confirmOrder.co_toyCount; i++) {
                    os << *confirmOrder.toys[i];
                }
            }
            os << "--------------------------\n";

            return os;
    }
}