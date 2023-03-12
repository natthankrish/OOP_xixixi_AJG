#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Card.hpp"

using namespace std;

class InventoryHolder {
    private:
        string type;
        virtual void operator+(const Card&) = 0;
        virtual void operator-(const Card&) = 0;
        
    public:
        InventoryHolder(string);
        void setType(string);
        string getType();

};

#endif
