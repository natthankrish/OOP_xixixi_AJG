#ifndef SORT_HPP
#define SORT_HPP

#include "../class/Card/NumberCard.hpp"
#include <vector>

class SortVector {
    public:
        static void sortByNumber(vector<NumberCard>&);
        static void sortByColorNumber(vector<NumberCard>&);
};

#endif