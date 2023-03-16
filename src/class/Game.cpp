#include "Game.hpp"
#include <iostream>
using namespace std;


Game::Game(int gameID) {
    this->prize = 64;
    this->maxPlayerPoint = 0;
    this->gameID = gameID;
    this->ascending = true;
}

long long int Game::startGame(List<Player>& listPlayer) {
    string game = "PERMAINAN " + to_string(this->gameID);
    displayTitle(game, "None");

    this->round = new Round(1, 1);
    round->startRound(listPlayer, this->prize, this->cardsBank, this->abilityCardsBank, this->tablecard, this->ascending);
    while (this->round->getRoundID() < 6) {
        NextRound();
        round->startRound(listPlayer, this->prize, this->cardsBank, this->abilityCardsBank, this->tablecard, this->ascending);
    }
    
    // pushing table card 
    vector<NumberCard> tempcard;
    while (tablecard.getCard().size() > 0) {
        tempcard.push_back(tablecard.getCard()[0]);
        tablecard - tablecard.getCard()[0];
    }

    vector<NumberCard> tempcard2;
    vector<NumberCard> tempcard3;
    LookUpTable table;
    vector<int> bestcomboarray;
    for (int i = 0; i < listPlayer.getNeff(); i++) {
        tempcard2.clear();
        for (int i = 0; i < tempcard.size(); i++) {
            tempcard2.push_back(tempcard[i]);
        }
        tempcard2.push_back(listPlayer.getElement(i).getPairOfCards().first);
        tempcard2.push_back(listPlayer.getElement(i).getPairOfCards().second);
        int bestCombo = 0;
        while (tempcard2.size() > 0) {
            tempcard3.clear();
            SortVector::sortByColorNumber(tempcard2);
            if (StraightFlush::getValue(tempcard2, table)){
                bestCombo += StraightFlush::getValue(tempcard2, table);
                tempcard3 = StraightFlush::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            } 

            SortVector::sortByNumber(tempcard2);
            if (FourOfKind::getValue(tempcard2, table)) {
                bestCombo += FourOfKind::getValue(tempcard2, table);
                tempcard3 = FourOfKind::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            if (FullHouse::getValue(tempcard2, table)) {
                bestCombo += FullHouse::getValue(tempcard2, table);
                tempcard3 = FullHouse::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            SortVector::sortByColorNumber(tempcard2);
            if (Flush::getValue(tempcard2, table)) {
                bestCombo += Flush::getValue(tempcard2, table); 
                tempcard3 = Flush::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            SortVector::sortByNumber(tempcard2);
            if (Straight::getValue(tempcard2, table)) {
                bestCombo += Straight::getValue(tempcard2, table);
                tempcard3 = Straight::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            if (ThreeOfKind::getValue(tempcard2, table)) {
                bestCombo += ThreeOfKind::getValue(tempcard2, table);
                tempcard3 = ThreeOfKind::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            if (TwoPair::getValue(tempcard2, table)) {
                bestCombo += TwoPair::getValue(tempcard2, table);
                tempcard3 = TwoPair::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            if (Pair::getValue(tempcard2, table)) {
                bestCombo += Pair::getValue(tempcard2, table);
                tempcard3 = Pair::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                continue;
            }
            if (High::getValue(tempcard2, table)) {
                bestCombo += High::getValue(tempcard2, table);
                tempcard3 = High::getCombo(tempcard2, table);
                for (auto ptr = tempcard3.begin(); ptr != tempcard3.end(); ptr++) {
                    if (find(tempcard2.begin(), tempcard2.end(), *ptr) != tempcard2.end()) {
                        auto ptrtemp = find(tempcard2.begin(), tempcard2.end(), *ptr);
                        tempcard2.erase(ptrtemp);
                    }
                }
                break;
                continue;
            }
        }
        bestcomboarray.push_back(bestCombo);
    }


    int index = 0;
    long long int maxPoint = bestcomboarray[0];
    for (int i = 1 ; i < bestcomboarray.size(); i++) {
        if(bestcomboarray[i] >= maxPoint) {
            maxPoint = bestcomboarray[i];
            index = i;
        }
    }
    listPlayer[index].updatePoint(this->prize);
    return getMaxList<Player>(listPlayer).getPoint();
}
    
void Game::NextRound() {
    int roundEnded = round->getRoundID();
    delete this->round;
    this->round = new Round(roundEnded+1, roundEnded+1);
}

AbilityCardsBank Game::getAbilityCardsBank() {
    return this->abilityCardsBank;
}
CardsBank Game::getCardsBank() {
    return this->cardsBank;
}

void Game::displayTitle(string title, string subtitle){
    string border = "==================================================" ;
    int whitespace = border.length() - title.length() - 4;
    int frontwhitespace = whitespace / 2;
    int backwhitespace = whitespace - frontwhitespace;
    cout << border << endl;
    cout << "==";
    for( int i = 0; i < frontwhitespace ; i++){
        cout << " ";
    }
    cout << title;
    for (int i = 0; i < backwhitespace; i++){
        cout << " ";
    }
    cout << "==" << endl;
    cout << border << endl;
    if (subtitle != "None"){
        int whitespace = border.length() - subtitle.length() - 4;
        int frontwhitespace = whitespace / 2;
        int backwhitespace = whitespace - frontwhitespace;
        cout << "==";
        for( int i = 0; i < frontwhitespace ; i++){
            cout << " ";
        }
        cout << subtitle;
        for (int i = 0; i < backwhitespace; i++){
            cout << " ";
        }
        cout << "==" << endl;
        cout << border << endl;
    }
}
