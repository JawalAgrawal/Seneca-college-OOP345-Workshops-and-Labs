/*
*****************************************************************************
                              Collection.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>

namespace sdds {
    template <typename T>
    class Collection {
    private:
        std::string m_name {};
        T* m_items {};
        size_t m_sizeOfItems {};
        void (*m_observerFuncPtr)(const Collection<T>&, const T&);
    public:
        // Sets the name of the collection to the string referred to by the parameter and sets all other attributes to their default value
        Collection(const std::string& name);

        // Destructor
        virtual ~Collection() {
            delete[] m_items;
        }

        // A query that returns the name of the collection
        const std::string& name() const;

        // A query that returns the number of items in the collection.
        size_t size() const;

        // Stores the address of the callback function (observer) into an attribute
        void setObserver(void (*observer)(const Collection<T>&, const T&));

        // Adds a copy of item to the collection, only if the collection doesn't contain an item with the same title
        Collection<T>& operator+=(const T& item);

        // Returns the item at index idx
        T& operator[](size_t idx) const;

        // Returns the address of the item with the title
        T* operator[](const std::string& title) const;
    };
}

#endif // SDDS_COLLECTION_H