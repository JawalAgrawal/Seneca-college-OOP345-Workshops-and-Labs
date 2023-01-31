/*
*****************************************************************************
                              Collection.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 01 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>

namespace sdds {
    template <typename T, unsigned int CAPACITY>
    class Collection {
    private:
        T items[CAPACITY];
        T dummyObject;
        inline static int elementsInCollection{};
    public:
        // Default constructor to set values to safe empty state
        Collection() {
            for (int i = 0; i < CAPACITY; i++) {
                items[i] = 0;
            }
        }

        // A query that returns the current number of elements in the collection
        int size() const {
            return elementsInCollection;
        }

        // Inserts into the stream all items from the collection
        std::ostream& display(std::ostream& os = std::cout) const {
            os << "----------------------" << std::endl;
            os << "| Collection Content |" << std::endl;
            os << "----------------------" << std::endl;

            // Inserting all the elements into the stream
            for (int i = 0; i < elementsInCollection; i++) {
                os << items[i] << std::endl;
            }

            os << "----------------------" << std::endl;
            return os;
        }

        // A mutator that adds a copy of the parameter to the collection if there still is capacity
        bool add(const T& item) {
            bool result = false;
            if (elementsInCollection < CAPACITY) {
                items[elementsInCollection] = item;
                // Incrementing the number of elements if an element was added
                elementsInCollection++;
            }

            return result;
        }

        // Returns a copy of the element stored in the collection at the specified index
        T& operator[](int index) const {
            T result{};
            if (index < 0 || index > CAPACITY) {
                result = dummyObject;
            } else {
                result = items[index];
            }

            return result;
        }
    };
}

#endif // SDDS_COLLECTION_H