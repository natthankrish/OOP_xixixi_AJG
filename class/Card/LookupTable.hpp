#ifndef LOOKUPTABLE_HPP
#define LOOKUPTABLE_HPP

#include <map>
#include <vector>
#include "NumberCard.hpp"

class LookUpTable {
    public: 
        std::map <NumberCard, double> cardValue;
        std::map <string, double> colorValue;
        const vector<string> COLORS = {"hijau, biru, kuning, merah"};

    public:
        LookUpTable();
        double getValue(string);
        double getValue(NumberCard);

};

#endif
