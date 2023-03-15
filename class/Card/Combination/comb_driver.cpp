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
#include "../Card.cpp"
#include <iostream>
#include <algorithm>

using namespace std;

const double Combination::MAX_VALUE = 2.0;

void sortByNumber(vector<NumberCard>& vec) {
    sort(vec.begin(), vec.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return a.getNumber() < b.getNumber(); 
    });
}

void sortByColorNumber(vector<NumberCard>& vec) {
    enum Color {hijau, biru, kuning, merah};

    sort(vec.begin(), vec.end(), 
        [](const NumberCard& a, const NumberCard& b) -> bool
    { 
        return 2* a.getColorWeight() + a.getNumber()*0.1 < 2*b.getColorWeight() + b.getNumber()*0.1; 
    });
}

void prettyPrint(vector<NumberCard> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].getNumber() << vec[i].getColor() << " ";
    }
    cout << endl;
}

int main() {
    LookUpTable table;

    vector<NumberCard> resultCombo;
    double resultValue;

    vector<NumberCard> deck1;
    vector<NumberCard> deck2;
    vector<NumberCard> deck3;
    vector<NumberCard> deck4;
    vector<NumberCard> deckA;
    vector<NumberCard> deckB;
    
    
    deck1.push_back(NumberCard(5, "merah"));
    deck1.push_back(NumberCard(5, "hijau"));
    deck1.push_back(NumberCard(9, "kuning"));
    deck1.push_back(NumberCard(5, "biru"));
    deck1.push_back(NumberCard(5, "kuning"));
    deck1.push_back(NumberCard(2, "kuning"));
    deck1.push_back(NumberCard(2, "kuning"));
    
    cout << "_______SORTING_________" << endl;
    sortByNumber(deck1);
    cout << "Sort by Number: ";
    prettyPrint(deck1);

    sortByColorNumber(deck1);
    cout <<"Sort by Color then Number: ";
    prettyPrint(deck1);

    cout << endl;
    cout << endl;

    // {"hijau", "biru", "kuning", "merah"}
    cout << "_______HIGH__________" << endl;
    /* WAJIB SORTING BY NUMBER */

    sortByNumber(deck1);
    cout << "Example Problem: ";
    prettyPrint(deck1);
    resultCombo = High::getCombo(deck1, table);
    resultValue = High::getValue(deck1, table);
    cout << "High: ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;
    cout << endl;

    deckA.push_back(NumberCard(1, "hijau"));
    deckB.push_back(NumberCard(13, "merah"));
    cout << "lower bound: " << High::getValue(deckA, table) << endl;
    cout << "upper bound: " << High::getValue(deckB, table) << endl;


    cout << "______PAIR________" << endl;
    cout << "Example Problem: ";
    prettyPrint(deck1);
    resultCombo = Pair::getCombo(deck1, table);
    resultValue = Pair::getValue(deck1, table);
    cout << "Pair: ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;
    cout << endl;

    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(1, "biru"));
    deckB.push_back(NumberCard(13, "kuning"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByNumber(deckA);
    sortByNumber(deckB);
    cout << "lower bound: " << Pair::getValue(deckA, table) << endl;
    cout << "upper bound: " << Pair::getValue(deckB, table) << endl;

    cout << "______TWOPAIR________" << endl;
    cout << "Example Problem: ";
    prettyPrint(deck1);
    resultCombo = TwoPair::getCombo(deck1, table);
    resultValue = TwoPair::getValue(deck1, table);
    cout << "TwoPair: ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;
    cout << endl;

    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(1, "biru"));
    deckA.push_back(NumberCard(1, "kuning"));
    deckA.push_back(NumberCard(1, "merah"));
    deckB.push_back(NumberCard(13, "hijau"));
    deckB.push_back(NumberCard(13, "biru"));
    deckB.push_back(NumberCard(13, "kuning"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByNumber(deckA);
    sortByNumber(deckB);
    cout << "lower bound: " << TwoPair::getValue(deckA, table) << endl;
    cout << "upper bound: " << TwoPair::getValue(deckB, table) << endl;

    cout << "______THREEOFKIND_______" << endl;
    cout << "Example Problem: ";
    prettyPrint(deck1);
    resultCombo = ThreeOfKind::getCombo(deck1, table);
    resultValue = ThreeOfKind::getValue(deck1, table);
    cout << "ThreeOfKind: ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;
    cout << endl;
    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(1, "biru"));
    deckA.push_back(NumberCard(1, "kuning"));
    deckB.push_back(NumberCard(13, "biru"));
    deckB.push_back(NumberCard(13, "kuning"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByNumber(deckA);
    sortByNumber(deckB);
    cout << "lower bound: " << ThreeOfKind::getValue(deckA, table) << endl;
    cout << "upper bound: " << ThreeOfKind::getValue(deckB, table) << endl;


    deck3.push_back(NumberCard(6, "merah"));
    deck3.push_back(NumberCard(7, "merah"));
    deck3.push_back(NumberCard(5, "hijau"));
    deck3.push_back(NumberCard(5, "biru"));
    deck3.push_back(NumberCard(4, "kuning"));
    deck3.push_back(NumberCard(3, "kuning"));
    deck3.push_back(NumberCard(2, "kuning"));

    sortByNumber(deck3);
    cout << "______STRAIGHT_______" << endl;
    cout << "Example Problem: ";
    prettyPrint(deck3);
    resultCombo = Straight::getCombo(deck3, table);
    resultValue = Straight::getValue(deck3, table);
    cout << "Straight ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;
    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(2, "hijau"));
    deckA.push_back(NumberCard(3, "hijau"));
    deckA.push_back(NumberCard(4, "hijau"));
    deckA.push_back(NumberCard(5, "hijau"));
    deckB.push_back(NumberCard(9, "merah"));
    deckB.push_back(NumberCard(10, "merah"));
    deckB.push_back(NumberCard(11, "merah"));
    deckB.push_back(NumberCard(12, "merah"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByNumber(deckA);
    sortByNumber(deckB);
    cout << "lower bound: " << Straight::getValue(deckA, table) << endl;
    cout << "upper bound: " << Straight::getValue(deckB, table) << endl;

    
    deck4.push_back(NumberCard(10, "merah"));
    deck4.push_back(NumberCard(8, "kuning"));
    deck4.push_back(NumberCard(5, "kuning"));
    deck4.push_back(NumberCard(10, "kuning"));
    deck4.push_back(NumberCard(5, "biru"));
    deck4.push_back(NumberCard(2, "kuning"));
    deck4.push_back(NumberCard(9, "kuning"));
    

    sortByColorNumber(deck4);


    cout << "______FLUSH_______" << endl;
    resultCombo = Flush::getCombo(deck4, table);
    resultValue = Flush::getValue(deck4, table);
    cout << "Example Problem: ";
    prettyPrint(deck4);
    cout << "Flush ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;

    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(2, "hijau"));
    deckA.push_back(NumberCard(3, "hijau"));
    deckA.push_back(NumberCard(4, "hijau"));
    deckA.push_back(NumberCard(5, "hijau"));
    deckB.push_back(NumberCard(9, "merah"));
    deckB.push_back(NumberCard(10, "merah"));
    deckB.push_back(NumberCard(11, "merah"));
    deckB.push_back(NumberCard(12, "merah"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByNumber(deckA);
    sortByNumber(deckB);
    cout << "lower bound: " << Flush::getValue(deckA, table) << endl;
    cout << "upper bound: " << Flush::getValue(deckB, table) << endl;

    cout << "______FOUROFKIND_______" << endl;
    cout << "Example Problem: ";
    prettyPrint(deck1);
    resultCombo = FourOfKind::getCombo(deck1, table);
    resultValue = FourOfKind::getValue(deck1, table);
    cout << "FourOfKind ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;

    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(1, "biru"));
    deckA.push_back(NumberCard(1, "kuning"));
    deckA.push_back(NumberCard(1, "merah"));
    deckB.push_back(NumberCard(13, "hijau"));
    deckB.push_back(NumberCard(13, "biru"));
    deckB.push_back(NumberCard(13, "kuning"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByNumber(deckA);
    sortByNumber(deckB);
    cout << "lower bound: " << FourOfKind::getValue(deckA, table) << endl;
    cout << "upper bound: " << FourOfKind::getValue(deckB, table) << endl;


    vector <NumberCard> deck5;
    deck5.push_back(NumberCard(1, "merah"));
    deck5.push_back(NumberCard(2, "kuning"));
    deck5.push_back(NumberCard(2, "merah"));
    deck5.push_back(NumberCard(3, "kuning"));
    deck5.push_back(NumberCard(3, "merah"));
    deck5.push_back(NumberCard(4, "merah"));
    deck5.push_back(NumberCard(5, "merah"));
    sortByColorNumber(deck5);

    cout << "______StraightFlush_______" << endl;
    cout << "Example Problem: ";
    prettyPrint(deck5);
    resultCombo = StraightFlush::getCombo(deck5, table);
    resultValue = StraightFlush::getValue(deck5, table);
    cout << "StraightFlush ";
    prettyPrint(resultCombo);
    cout << "value: " << resultValue << endl;
    deckA.clear();
    deckB.clear();
    deckA.push_back(NumberCard(1, "hijau"));
    deckA.push_back(NumberCard(2, "hijau"));
    deckA.push_back(NumberCard(3, "hijau"));
    deckA.push_back(NumberCard(4, "hijau"));
    deckA.push_back(NumberCard(5, "hijau"));
    
    deckB.push_back(NumberCard(9, "merah"));
    deckB.push_back(NumberCard(10, "merah"));
    deckB.push_back(NumberCard(11, "merah"));
    deckB.push_back(NumberCard(12, "merah"));
    deckB.push_back(NumberCard(13, "merah"));
    sortByColorNumber(deckA);
    sortByColorNumber(deckB);
    cout << "lower bound: " << StraightFlush::getValue(deckA, table) << endl;
    cout << "upper bound: " << StraightFlush::getValue(deckB, table) << endl;
    

    
    return 0;
}