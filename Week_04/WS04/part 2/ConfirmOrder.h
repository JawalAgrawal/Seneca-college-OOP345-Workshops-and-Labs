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

        // Adds the toy to the array by adding its address
        ConfirmOrder& operator+=(const Toy& toy);

        // Removes the toy from the array by removing its address
        ConfirmOrder& operator-=(const Toy& toy);

        // Insert the content of a ConfirmOrder object into an ostream object
        friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirmOrder);
    };
}

#endif // SDDS_CONFIRMORDER_H