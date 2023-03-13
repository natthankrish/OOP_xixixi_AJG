#include "ChangePlayerCard.hpp"
#include <iostream> 
#include <fstream>
using namespace std;

ChangePlayerCard::ChangePlayerCard(string type, string name) : OrdinaryCommand("ordinary", "changenum"){   

}

bool ChangePlayerCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void ChangePlayerCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
    string filename;
    cout << "Masukkan nama file dengan ekstensi .txt: ";
    cin >> filename;

    ifstream infile(filename); // sementara
    while (!infile.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        cout << "Masukkan ulang nama file dengan ekstensi .txt: ";
        cin >> filename;
        ifstream infile(filename); // sementara
    } 
    
    string word;
    int num;
    int count = 0;

    // taking all of the number cards from player
    while (count < 7) {
        if (listPlayer.getElement(count).getPairOfCards().first != NumberCard() && listPlayer.getElement(count).getPairOfCards().second != NumberCard()) {
            cout << "Masuk taking all of the number cards from player, kartu number tidak kosong" << endl; 
            cardsbank + listPlayer[count].operator--();
            cardsbank + listPlayer[count].operator--();
        }
        count++;
    }

    // bagi ulang dengan spesifikasi dari file
    count = 0;
    while (count < 7) {
        for (int i = 0; i < 4; i++) {
            if (infile >> word) {
                // cout << word << " ";0
                if (isNum(word)) {
                    num = stringToInt(word);
                } else {
                    NumberCard temp(num, word);
                    // cout << temp.getNumber() << " " << temp.getColor() << endl;
                    listPlayer[count] + temp;
                    // cout << listPlayer.getElement(count).getPairOfCards().first.getNumber() << listPlayer.getElement(count).getPairOfCards().first.getColor() << endl;
                    cardsbank - temp; 
                }  
            }
        }
        count++;
    }
    cout << endl;

    // taking all of the ability cards from player
    count = 0;
    while (count < 7) {
        if (listPlayer.getElement(count).getAbilityCard() != AbilityCard()) {
            cout << "Masuk taking all of the ability cards from player, kartu ability tidak kosong" << endl; 
            AbilityCard temp = listPlayer.getElement(count).getAbilityCard();
            abilitycardsbank + temp;          
            listPlayer[count] - temp;
        }
        count++;
    }

    // bagi ulang semua kartu ability dari input file
    count = 0; 
    while (count < 7 && infile >> word) {
        // cout << word << endl;
        AbilityCard temp(word);
        listPlayer[count] + temp; 
        abilitycardsbank - temp;
        count++; 
    }

    infile.close();

    // checking
    for (int i = 0; i < 7; i++) {
        cout << i << " " << listPlayer.getElement(i).getPairOfCards().first.getNumber() << " " 
        << listPlayer.getElement(i).getPairOfCards().first.getColor() << endl;
        cout << i << " " << listPlayer.getElement(i).getPairOfCards().second.getNumber() << " " 
        << listPlayer.getElement(i).getPairOfCards().second.getColor() << endl;
        cout << listPlayer.getElement(i).getAbilityCard().getAbilityName() << endl;  
    }
}

int ChangePlayerCard::stringToInt(string word) {
    if (word == "1") {
        return 1;
    }
    if (word == "2") {
        return 2;
    }
    if (word == "3") {
        return 3;
    }
    if (word == "4") {
        return 4;
    }
    if (word == "5") {
        return 5;
    }
    if (word == "6") {
        return 6;
    }
    if (word == "7") {
        return 7;
    }
    if (word == "8") {
        return 8;
    }
    if (word == "9") {
        return 9;
    }
    if (word == "10") {
        return 10;
    }
    if (word == "11") {
        return 11;
    }
    if (word == "12") {
        return 12;
    }
    if (word == "13") {
        return 13;
    }
    return -1;
}

bool ChangePlayerCard::isNum(string word) {
    if (word == "1" ||
        word == "2" ||
        word == "3" ||
        word == "4" ||
        word == "5" ||
        word == "6" ||
        word == "7" ||
        word == "8" ||
        word == "9" ||
        word == "10" ||
        word == "11" ||
        word == "12" ||
        word == "13") {
            return true;
    } else {
        return false;
    }
        
}

// int main() {
//     CardsBank cardsbank;
//     AbilityCardsBank abilitybank;
//     List<Player>* ListOfPlayer = new List<Player>(7);
//     for (int i = 0;i < 7; i++) {
//         string playerName;
//         cout << "Masukkan nama player " << i+1 << ": ";
//         cin >> playerName;
//         Player* player = new Player(1, playerName, 0, false);
//         ListOfPlayer->insertLast(*player);
//     }

//     cardsbank.bagiKartu(*ListOfPlayer);
//     abilitybank.bagiAbility(*ListOfPlayer);
//     for (int i = 0; i < 7; i++) {
//         cout << i << " " << ListOfPlayer->getElement(i).getPairOfCards().first.getNumber() << " " 
//         << ListOfPlayer->getElement(i).getPairOfCards().first.getColor() << endl;
//         cout << i << " " << ListOfPlayer->getElement(i).getPairOfCards().second.getNumber() << " " 
//         << ListOfPlayer->getElement(i).getPairOfCards().second.getColor() << endl;
//         cout << ListOfPlayer->getElement(i).getAbilityCard().getAbilityName() << endl;  
//     }
//     ChangePlayerCard change("numberability", "Player");
//     int prize = 0;
//     change.execute(*ListOfPlayer, 0, prize, cardsbank, abilitybank);
// }