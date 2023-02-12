#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include "Toy.h"

namespace sdds {
    class Child {
    private:
        std::string c_name {};
        int c_age {};
        const sdds::Toy** toys {};
        int c_toyCount {};
    public:
        // Default Constructor
        Child() = default;

        // Constructor stores copies of all toys
        Child(std::string name, int age, const Toy* toys[], size_t count);

        // Rule of 5
        // Copy Semantics
        Child(const Child& src);
        Child& operator=(const Child& src);

        // Move Semantics
        Child(Child&& src) noexcept;
        Child& operator=(Child&& src) noexcept;

        // Returns the number of toys stored in the array attribute
        size_t size() const;

        // Insert the content of a Child object into an ostream object
        friend std::ostream& operator<<(std::ostream& os, const Child& child);
    };
}

#endif // SDDS_CHILD_H