#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"
using namespace std;

class FullHouse : Combination {
    public: 
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif