#ifndef THREE_OF_KIND_HPP
#define THREE_OF_KIND_HPP

#include <vector>
#include "Combination.hpp"
#include "../NumberCard.hpp"
#include "../LookUpTable.hpp"

using namespace std;

class ThreeOfKind : public Combination {
    public:
        static double getValue(vector<NumberCard>, LookUpTable);
        static vector<NumberCard> getCombo(vector<NumberCard>, LookUpTable);
};

#endif