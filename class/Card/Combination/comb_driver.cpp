#include "Combination.hpp"
#include "High.cpp"
#include "Pair.cpp"
#include "TwoPair.cpp"
#include "Flush.cpp"
#include "ThreeOfKind.cpp"
#include "FourOfKind.cpp"
#include "FullHouse.cpp"
#include "Straight.cpp"
#include "StraightFlush.cpp"
#include "../LookupTable.cpp"
#include "../NumberCard.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

void prettyPrint(vector<NumberCard> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].getNumber() << vec[i].getColor() << " ";
    }
    cout << endl;
}

int main() {
    LookUpTable table;
    vector<NumberCard> result;
    vector<NumberCard> deck1;
    vector<NumberCard> deck2;
    vector<NumberCard> deck3;
    vector<NumberCard> deck4;
    
    
    // FOUR OF KIND
    deck1.push_back(NumberCard(5, "merah"));
    deck1.push_back(NumberCard(5, "hijau"));
    deck1.push_back(NumberCard(5, "biru"));
    deck1.push_back(NumberCard(5, "kuning"));
    deck1.push_back(NumberCard(2, "kuning"));
    deck1.push_back(NumberCard(2, "kuning"));
    
    sort(deck1.begin(), deck1.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return a.getNumber() > b.getNumber(); 
    });

    result = FourOfKind::getCombo(deck1, table);
    prettyPrint(result);

    // FULL HOUSE
    deck2.push_back(NumberCard(7, "merah"));
    deck2.push_back(NumberCard(5, "hijau"));
    deck2.push_back(NumberCard(5, "biru"));
    deck2.push_back(NumberCard(5, "kuning"));
    deck2.push_back(NumberCard(2, "kuning"));
    deck2.push_back(NumberCard(2, "kuning"));

    sort(deck2.begin(), deck2.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return a.getNumber() > b.getNumber(); 
    });
    
    // STRAIGHT
    deck3.push_back(NumberCard(5, "merah"));
    deck3.push_back(NumberCard(5, "hijau"));
    deck3.push_back(NumberCard(5, "biru"));
    deck3.push_back(NumberCard(4, "kuning"));
    deck3.push_back(NumberCard(3, "kuning"));
    deck3.push_back(NumberCard(2, "kuning"));

    sort(deck3.begin(), deck3.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return a.getNumber() > b.getNumber(); 
    });
    // FLUSH
    deck4.push_back(NumberCard(10, "merah"));
    deck4.push_back(NumberCard(8, "kuning"));
    deck4.push_back(NumberCard(5, "kuning"));
    deck4.push_back(NumberCard(5, "kuning"));
    deck4.push_back(NumberCard(2, "kuning"));
    deck4.push_back(NumberCard(2, "kuning"));
    
    sort(deck4.begin(), deck4.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return a.getNumber() > b.getNumber(); 
    });

    

    
    
    
    return 0;
}