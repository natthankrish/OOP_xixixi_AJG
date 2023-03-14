#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP
#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"


class TwoPair : public Combination {
    public:
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif