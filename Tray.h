#ifndef TRAY_H
#define TRAY_H

#include <iostream>
#include <vector>
#include "Egg.h"

class Tray {
public:
    Tray(); // Default constructor
    ~Tray(); // Destructor - Purpose: release the memory allocated to carton

    // Overloads the output stream operator for Tray objects
    friend std::ostream& operator<<(std::ostream& os, const Tray& rhs);
    
    // Places a new egg at the back of the tray
    void place_back(Egg new_egg);

    // Compares two Tray objects for equality
    friend bool operator==(const Tray& lhs, const Tray& rhs);

    // Places an egg at the front of the tray
    void place_front(Egg e);

    // Removes a specified egg from the tray
    void remove(Egg e);

    bool take_back(Egg& e);

private:
    int capacity; // Total capacity of the tray
    int current_number_of_eggs; // Current number of eggs in the tray
    Egg* carton; // Dynamically allocated array of Eggs
};

#endif // TRAY_H
