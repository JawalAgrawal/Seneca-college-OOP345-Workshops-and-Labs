#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>

// Global Variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
    class FoodOrder {
    private:
        char* customerName;
        char* foodDescription;
        double foodPrice;
        bool dailySpecial;

        // Initializes all attributes to safe empty state
        void setEmpty();

        // Frees all the dynamically allocated memory
        void deallocate();

    public:
        FoodOrder();
        ~FoodOrder();

        // Reads a line in the text file and stores data in class
        std::istream& read(std::istream& is);

        // Displays data
        void display() const;
    };
}

#endif // SDDS_FOODORDER_H