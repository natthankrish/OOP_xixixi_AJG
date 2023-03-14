#include "Game.hpp"
#include <iostream>

using namespace std;


Game::Game(int gameID) {
    this->prize = 64;
    this->maxPlayerPoint = 0;
    this->gameID = gameID;
    this->ascending = true;
}

int Game::startGame(List<Player>& listPlayer) {
    // string game = "PERMAINAN " + to_string(this->gameID);
    // displayTitle(game, "None");

    this->round = new Round(1, 1);
    round->startRound(listPlayer, this->prize, this->cardsBank, this->abilityCardsBank, this->tablecard, this->ascending);
    while (this->round->getRoundID() < 6) {
        NextRound();
        round->startRound(listPlayer, this->prize, this->cardsBank, this->abilityCardsBank, this->tablecard, this->ascending);
    }
    
    // displayTitle("PERMAINAN SELESAI", "None");
    return 0;
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

string Game::displayTitle(string title, string subtitle){
    string border = "==============================================" ;
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
