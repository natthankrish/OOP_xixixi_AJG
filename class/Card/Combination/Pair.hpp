#ifndef PAIR_HPP
#define PAIR_HPP

#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"
using namespace std;

class Pair : Combination{
    public:
        Pair(vector <NumberCard>);
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};


#endif