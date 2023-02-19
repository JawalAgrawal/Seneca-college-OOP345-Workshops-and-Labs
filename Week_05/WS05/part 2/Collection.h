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
        Collection(const std::string& name) {
            m_name = name;
            m_items = nullptr;
            m_sizeOfItems = 0;
            m_observerFuncPtr = nullptr;
        }

        // Delete Copy operations
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection(Collection&& collection) = delete;
        Collection& operator=(Collection&& collection) = delete;

        // Destructor
        virtual ~Collection() { delete[] m_items; }

        // A query that returns the name of the collection
        const std::string& name() const { return m_name; }

        // A query that returns the number of items in the collection.
        size_t size() const { return m_sizeOfItems; }

        // Stores the address of the callback function (observer) into an attribute
        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observerFuncPtr = observer;
        }

        // Adds a copy of item to the collection, only if the collection doesn't contain an item with the same title
        Collection& operator+=(const T& item) {
            bool duplicate = false;
            // Check if the item that we are trying to add is not a duplicate
            // Not using range based loop as DMA is involved
            for (size_t i = 0; i < m_sizeOfItems; ++i) {
                if (m_items[i].title() == item.title()) {
                    duplicate = true;
                }
            }

            if (!duplicate) {
                T* temp = new T[m_sizeOfItems + 1];
                for (size_t i = 0; i < m_sizeOfItems; i++) {
                    temp[i] = m_items[i];
                }

                temp[m_sizeOfItems] = item;

                delete[] m_items;
                m_items = temp;
                m_sizeOfItems++;

                // Calling the observer function if registered
                if (m_observerFuncPtr) {
                    m_observerFuncPtr(*this, item);
                }
            }

            return *this;
        }

        // Returns the item at index idx
        T& operator[](size_t idx) const {
            // Throwing an exception if the index is out of range
            if (idx >= m_sizeOfItems) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_sizeOfItems) + "] items.");
            }

            return m_items[idx];
        }

        // Returns the address of the item with the title
        T* operator[](const std::string& title) const {
            T* itemAddress = nullptr;

            for (size_t i = 0; i < m_sizeOfItems; ++i) {
                if (m_items[i].title() == title) {
                    itemAddress = &m_items[i];
                }
            }

            return itemAddress;
        }
    };

    // Overloading the insertion operator
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
        for (size_t i = 0; i < collection.size(); i++) {
            os << collection[i];
        }
        return os;
    }
}

#endif // SDDS_COLLECTION_H