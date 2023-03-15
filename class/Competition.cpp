#include <iostream>
#include "Competition.hpp"
#include "Game.hpp"
#include "inventory/InventoryHolder.hpp"
#include <math.h> 


using namespace std;

Competition::Competition() {
    // cout << "INISIALISASI PLAYER DAN DECK" << endl;
    displayTitle("INISIALISASI PLAYER DAN DECK", "None");
    this->ListOfPlayer = new List<Player>(7);
    for (int i = 0;i < 7; i++) {
        string playerName;
        cout << "Masukkan nama player " << i+1 << ": " << endl;
        cout << "=> ";
        cin >> playerName;
        Player* player = new Player(1, playerName, 0, false);
        ListOfPlayer->insertLast(*player);
    }
    
}

void Competition::startCompetition() {
    // cout << "MEMULAI PERMAINAN" << endl;
    displayTitle("MEMULAI PERMAINAN", "None");

    this->currentGame = new Game(1);
    long long int maxPoint = currentGame->startGame(*(this->ListOfPlayer));
    int i = 2;
    cout << "MaxPoint: " << maxPoint << endl;
    while (maxPoint < pow(2, 32)) {
        this->currentGame = new Game(i);
        maxPoint = currentGame->startGame(*(this->ListOfPlayer));
        i++;
    }
    
    // sorting
    int a = 0;
    for (int j = 0; j < ListOfPlayer->getNeff(); j++) {
        long long int max = ListOfPlayer->getElement(j).getPoint();
        int idxMax = j;
        for (int k = j; k < ListOfPlayer->getNeff(); k++) {
            if (max < ListOfPlayer->getElement(k).getPoint()){
                max = ListOfPlayer->getElement(k).getPoint();
                idxMax = k;
            }
        }
        Player temp;
        temp = ListOfPlayer->getElement(j);  
        ListOfPlayer->setElementAt(j,  ListOfPlayer->getElement(idxMax));
        ListOfPlayer->setElementAt(idxMax, temp);
    } 

    cout << "Permainan berakhir." << endl;
    displayTitle("Leaderboard", "None");
    for(int x = 1; x <= ListOfPlayer->getNeff(); x++) {
        cout << x << ". " << ListOfPlayer->getElement(x-1).getName() << ": " << ListOfPlayer->getElement(x-1).getPoint() << endl;
    }
    cout << "Permainan dimenangkan oleh " << ListOfPlayer->getElement(0).getName() << "." << endl;
}

void Competition::displayTitle(string title, string subtitle){
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


