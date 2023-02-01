/*
*****************************************************************************
                              Set.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 01 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include "Collection.h"

namespace sdds {
    template<typename T>
    class Set : public Collection<T, 100> {
    public:
        // A mutator that adds a copy of the parameter to the collection if there still is capacity and the item is not repeated
        virtual bool add(const T& item) {
            int duplicateCount = 0;
            bool result = false;

            // Looping through the array and counting the number od duplicates
            for (int i = 0; i < Collection<T, 100>::size(); i++) {
                if (item == Collection<T, 100>::operator[](i)) {
                    duplicateCount++;
                }
            }

            // Adding the item to the array if there are no duplicates
            if (duplicateCount == 0) {
                this->Collection<T, 100>::add(item);
            }

            return result;
        }
    };
}

#endif // SDDS_SET_H
