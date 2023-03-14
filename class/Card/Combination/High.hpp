#ifndef HIGH_H
#define HIGH_H

#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"
using namespace std;

class High : Combination {
    public: 
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif