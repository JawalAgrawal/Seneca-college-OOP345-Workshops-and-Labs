/*
*****************************************************************************
                              Child.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Child.h"
#include <iostream>

namespace sdds {
    // Constructor stores copies of all toys
    Child::Child(std::string name, int age, const Toy* toysArr[], size_t count) : c_name(name), c_age(age), c_toyCount(count) {
        if (count > 0) {
            // Dynamically allocating memory for the toys array
            toys = new const Toy*[c_toyCount];
            for (size_t i = 0; i < c_toyCount; i++) {
                // Creating a new toy object from target of src.toys at i
                toys[i] = new Toy(*(toysArr[i]));
            }
        } else {
            toys = nullptr;
        }
    }

    // ========== Rule of 5 ==========
    // Copy Semantics
    Child::Child(const Child& src) {
        *this = src;
    }

    Child& Child::operator=(const Child& src) {
        if (this != &src) {
            // Deleting the dynamically allocated memory
            for (size_t i = 0; i < c_toyCount; i++) {
                delete toys[i];
            }
            delete[] toys;
            toys = nullptr;

            // Copying
            if (src.toys) {
                toys = new const Toy*[src.c_toyCount];
                for (size_t i = 0; i < src.c_toyCount; i++) {
                    toys[i] = new Toy(*(src.toys[i]));
                }
            }
            c_name = src.c_name;
            c_age = src.c_age;
            c_toyCount = src.c_toyCount;
        }

        return *this;
    }

    // Move Semantics
    Child::Child(Child&& src) noexcept {
        *this = std::move(src);
    }

    Child& Child::operator=(Child&& src) noexcept {
        if (this != &src) {
            // Deleting the dynamically allocated memory
            for (size_t i = 0; i < c_toyCount; i++) {
                delete toys[i];
            }
            delete[] toys;
            toys = nullptr;

            // Moving
            toys = src.toys;
            src.toys = nullptr;
            c_name = src.c_name;
            src.c_name = "";
            c_age = src.c_age;
            src.c_age = 0;
            c_toyCount = src.c_toyCount;
            src.c_toyCount = 0;
        }

        return *this;
    }

    // Destructor
    Child::~Child() {
        for (size_t i = 0; i < c_toyCount; i++) {
            delete toys[i];
        }
        delete[] toys;
    }

    // Returns the number of toys stored in the array attribute
    size_t Child::size() const {
        return c_toyCount;
    }

    // Insert the content of a Child object into an ostream object
    std::ostream& operator<<(std::ostream& os, const Child& child) {
        static int call_cnt {1};
        os << "--------------------------" << std::endl;
        os << "Child " << call_cnt << ": " << child.c_name << " " << child.c_age << " years old:" << std::endl;
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

        call_cnt++;
        return os;
    }
}