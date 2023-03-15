#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP
#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"
using namespace std;

class StraightFlush : public Combination{
    public:
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif