#ifndef FOUR_OF_KIND_HPP
#define FOUR_OF_KIND_HPP

#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"

using namespace std;

class FourOfKind : public Combination {
    public: 
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif