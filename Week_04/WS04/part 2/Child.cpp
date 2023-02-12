#include "Child.h"
#include <iostream>

namespace sdds {
    // Constructor stores copies of all toys
    Child::Child(std::string name, int age, const Toy* toysArr[], size_t count) : c_name(name), c_age(age), c_toyCount(count) {
        if (count > 0) {
            // Dynamically allocating memory for the toys array
            toys = new const Toy*[c_toyCount];
            for (size_t i = 0; i < c_toyCount; i++) {
                toys[i] = toysArr[i];
            }
        } else {
            toys = nullptr;
        }
    }

    // Rule of 5
    // Copy Semantics
    Child::Child(const Child& src) {
        *this = src;
    }

    Child& Child::operator=(const Child& src) {
        if (this != &src) {
            c_name = src.c_name;
            c_age = src.c_age;
            c_toyCount = src.c_toyCount;

            // Dynamically allocating memory for the toys arrau
            toys = new const Toy*[src.c_toyCount];
            for (size_t i = 0; i < src.c_toyCount; i++) {
                toys[i] = src.toys[i];
            }
        }

        return *this;
    }

    // Move Semantics
    Child::Child(Child&& src) noexcept {
        *this = std::move(src);
    }

    Child& Child::operator=(Child&& src) noexcept {
        if (this != &src) {
            c_name = src.c_name;
            c_age = src.c_age;
            c_toyCount = src.c_toyCount;

            // Dynamically allocating memory for the toys arrau
            toys = new const Toy*[src.c_toyCount];
            for (size_t i = 0; i < src.size(); i++) {
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

    // Returns the number of toys stored in the array attribute
    size_t Child::size() const {
        return c_toyCount;
    }

    // Insert the content of a Child object into an ostream object
    std::ostream& operator<<(std::ostream& os, const Child& child) {
        int CALL_CNT = 1;
        os << "--------------------------" << std::endl;
        os << "Child " << CALL_CNT << ": " << child.c_name << " " << child.c_age << " years old:" << std::endl;
        os << "--------------------------" << std::endl;
        if (child.size() > 0) {
            for (size_t i = 0; i < child.size(); i++) {
                os << *child.toys[i];
            }
        }
        else {
            os << "This child has no toys!" << std::endl;
        }

        os << "--------------------------" << std::endl;

        CALL_CNT++;
        return os;
    }
}