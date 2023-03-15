#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP
#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"
using namespace std;

class Straight : public Combination {
    public:
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif