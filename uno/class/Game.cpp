#include "Game.hpp"
#include <iostream>

using namespace std;


Game::Game(int gameID) {
    this->gameID = gameID;
}

int Game::startGame(List<Player>& listPlayer) {
    displayTitle("PERMAIAN UNO DIMULAI","None");
    this->round = new Round(1, 1);
    round->startRound(listPlayer, this->cardsBank, this->tablecard);
    
    cout << "Peringkat: " << endl; {
        for (int i = 0; i < listPlayer.getNeff(); i++) {
            cout << i+1 << ". " << listPlayer[i].getName() << endl;
        }
    }
    displayTitle("PERMAIAN SELESAI","None");
    return 0;
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

