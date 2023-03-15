#include "sort.hpp"
#include <algorithm>

void SortVector::sortByNumber(vector<NumberCard>& vec) {
    sort(vec.begin(), vec.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return a.getNumber() < b.getNumber(); 
    });
}
void SortVector::sortByColorNumber(vector<NumberCard>& vec) {
    enum Color {hijau, biru, kuning, merah};

    sort(vec.begin(), vec.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return 2* a.getColorWeight() + a.getNumber()*0.1 < 2*b.getColorWeight() + b.getNumber()*0.1; 
    });
}
