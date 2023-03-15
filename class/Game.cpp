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

    LookUpTable table;
    vector<int> bestcomboarray;
    for (int i = 0; i < listPlayer.getNeff(); i++) {
        tempcard.push_back(listPlayer.getElement(i).getPairOfCards().first);
        tempcard.push_back(listPlayer.getElement(i).getPairOfCards().second);
        
        int bestCombo = 0;
        SortVector::sortByColorNumber(tempcard);
        if (StraightFlush::getValue(tempcard, table) > bestCombo){
            bestCombo = StraightFlush::getValue(tempcard, table); 
        } else if (Flush::getValue(tempcard, table) > bestCombo) {
            bestCombo = Flush::getValue(tempcard, table); 
        }

        SortVector::sortByNumber(tempcard);
        if (FourOfKind::getValue(tempcard, table) > bestCombo) {
            bestCombo = FourOfKind::getValue(tempcard, table);
        }
        else if (FullHouse::getValue(tempcard, table) > bestCombo) {
            bestCombo = FullHouse::getValue(tempcard, table);
        }
        else if (Flush::getValue(tempcard, table) > bestCombo) {
            bestCombo = Flush::getValue(tempcard, table);
        }
        else if (Straight::getValue(tempcard, table) > bestCombo) {
            bestCombo = Straight::getValue(tempcard, table);
        }
        else if (ThreeOfKind::getValue(tempcard, table) > bestCombo) {
            bestCombo = ThreeOfKind::getValue(tempcard, table);
        }
        else if (TwoPair::getValue(tempcard, table) > bestCombo) {
            bestCombo = TwoPair::getValue(tempcard, table);
        }
        else if (Pair::getValue(tempcard, table) > bestCombo) {
            bestCombo = Pair::getValue(tempcard, table);
        }
        bestcomboarray.push_back(bestCombo);
    }


    int index;
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
