#include "ChangeTableCard.hpp"
#include <iostream> 
#include <fstream>
using namespace std;

ChangeTableCard::ChangeTableCard(string type, string name) : OrdinaryCommand("ordinary", "changenum"){   

}

bool ChangeTableCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void ChangeTableCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    string filename;
    cout << "Masukkan nama file card player dengan ekstensi .txt: ";
    cin >> filename;

    ifstream infile(filename); // sementara
    while (!infile.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        cout << "Masukkan ulang nama file card player dengan ekstensi .txt: ";
        cin >> filename;
        ifstream infile(filename); // sementara
    } 
    
    string word;
    int num;
    int count = 0;

    cout << "Cardsbank size: " << cardsbank.getElement().size() << endl;
    // taking all of the number cards from player
    while (count < 7) {
        if (listPlayer.getElement(count).getPairOfCards().first != NumberCard() && listPlayer.getElement(count).getPairOfCards().second != NumberCard()) {
            cout << "Masuk taking all of the number cards from player, kartu number tidak kosong" << endl; 
            cardsbank + listPlayer[count].operator--();
            cardsbank + listPlayer[count].operator--();
        }
        count++;
    }

    // taking all table cards
    int countTableCard = tablecard.getCard().size();
    vector<NumberCard> temp0;
    while (tablecard.getCard().size() > 0) {
        // cout << "Error?" << endl;
        // cout << tablecard.getCard()[0].getNumber() << tablecard.getCard()[0].getColor() << endl; 
        NumberCard temp(tablecard.getCard()[0].getNumber(), tablecard.getCard()[0].getColor());
        temp0.push_back(temp);
        tablecard - temp;
        cardsbank + temp;
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
    infile.close();

    cout << "Masukkan nama file ability card player dengan ekstensi .txt: ";
    cin >> filename;

    ifstream infile2(filename); // sementara
    while (!infile2.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        cout << "Masukkan ulang nama file ability card player dengan ekstensi .txt: ";
        cin >> filename;
        ifstream infile2(filename); // sementara
    } 

    // taking all of the ability cards from player
    bool hasAbilityCard = false;
    count = 0;
    while (count < 7) {
        if (listPlayer.getElement(count).getAbilityCard() != AbilityCard()) {
            cout << "Masuk taking all of the ability cards from player, kartu ability tidak kosong" << endl; 
            hasAbilityCard = true;
            AbilityCard temp = listPlayer.getElement(count).getAbilityCard();
            abilitycardsbank + temp;          
            listPlayer[count] - temp;
        }
        count++;
    }

    // bagi ulang semua kartu ability dari input file
    if (hasAbilityCard) {
        count = 0; 
        while (count < 7 && infile2 >> word) {
            cout << word << endl;
            AbilityCard temp(word);
            listPlayer[count] + temp; 
            abilitycardsbank - temp;
            count++; 
        }
    } else {
        // clearing the abilitycardsbank
        while (abilitycardsbank.getElement().size()) {
            abilitycardsbank - abilitycardsbank.getElementAt(0);
        }
        count = 0; 
        while (count < 7 && infile2 >> word) {
            AbilityCard temp(word);
            abilitycardsbank + temp;
            count++;
        }
    } 

    infile2.close();

    // penggantian table card
    cout << "Masukkan nama file table card dengan ekstensi .txt: ";
    cin >> filename;

    ifstream infile3(filename); // sementara
    while (!infile3.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        cout << "Masukkan ulang nama file table card dengan ekstensi .txt: ";
        cin >> filename;
        ifstream infile3(filename); // sementara
    }

    string word;
    int num;
    int count = 0;



    cout << "Cardsbank size: " << cardsbank.getElement().size() << endl;
    // checking if all the table cards from the input are in cardsbank
    // taking all the cards back from the table to cards bank

    vector<NumberCard> temp;
    for (int i = 0; i < 5*2; i++) {
        if (infile3 >> word) {
            if (isNum(word)) {
                num = stringToInt(word);
            } else {
                temp.push_back(NumberCard(num, word));
            }
        } else {
            for (int i = 0; i < countTableCard; i++) {
                tablecard + temp0[i];
            }
            throw TableCardDoNotMatch();
        }
    } 

    cout << "Cardsbank size: " << cardsbank.getElement().size() << endl;
    for (int i = 0; i < 5; i++) {
        try {
            cardsbank - temp[i];
        } catch (CardNotFoundException e) {
            // returning the cards back to the cards bank
            for (int j = 0; j < i-1; j++) {
                cardsbank + temp[j];
            }
            cout << e.what() << endl;
            cout << "Gagal mengganti table card karena kartu tidak terdapat pada cardsbank" << endl;
        }
    }

    // all cards from the input file are found in the cards bank
    // placing the cards from the input file to the table card
    for (int i = 0; i < countTableCard; i++) {
        cardsbank - temp[0];
        tablecard + temp[0];
        temp.erase(temp.begin());
    }

    // placing the rest of the table card
    while (temp.size() > 0) {
        // placing the rest of the cards on top of the cardsbank
        cardsbank - temp[0];
        cardsbank + temp[0];
        temp.erase(temp.begin());
    }
    

    infile3.close();
    // checking
    for (int i = 0; i < countTableCard; i++) {
        cout << tablecard.getCard()[i].getNumber() << " " 
        << tablecard.getCard()[i].getColor() << endl;
    }
}

int ChangeTableCard::stringToInt(string word) {
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

bool ChangeTableCard::isNum(string word) {
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

int main() {
    CardsBank cardsbank;
    AbilityCardsBank abilitybank;
    List<Player>* ListOfPlayer = new List<Player>(7);
    for (int i = 0;i < 7; i++) {
        string playerName;
        cout << "Masukkan nama player " << i+1 << ": ";
        cin >> playerName;
        Player* player = new Player(1, playerName, 0, false);
        ListOfPlayer->insertLast(*player);
    }
    TableCard tablecard;
    ChangeTableCard change("tablecard", "card");
    ChangePlayerCard change2("playercard", "card");
    int prize = 0;

    for (int i = 0; i < tablecard.getCard().size(); i++) {
        cout << tablecard.getCard()[i].getNumber() << " " << tablecard.getCard()[i].getColor() << endl;
    }

    // bagi kartu untuk player
    cardsbank.bagiKartu(*ListOfPlayer);
    tablecard + cardsbank.getElementAt(0);
    cardsbank - cardsbank.getElementAt(0);
    tablecard + cardsbank.getElementAt(0);
    cardsbank - cardsbank.getElementAt(0);
    tablecard + cardsbank.getElementAt(0);
    cardsbank - cardsbank.getElementAt(0);
    change2.execute(tablecard, *ListOfPlayer, 0, prize, cardsbank, abilitybank, true);
    try {
        change.execute(tablecard, *ListOfPlayer, 0, prize, cardsbank, abilitybank, true);
    } catch (TableCardDoNotMatch e) {
        cout << e.what() << endl; 
    }

    // bagi ability 
    abilitybank.bagiAbility(*ListOfPlayer);
       // checking
    for (int i = 0; i < 7; i++) {
        cout << i << " " << ListOfPlayer->getElement(i).getPairOfCards().first.getNumber() << " " 
        << ListOfPlayer->getElement(i).getPairOfCards().first.getColor() << endl;
        cout << i << " " << ListOfPlayer->getElement(i).getPairOfCards().second.getNumber() << " " 
        << ListOfPlayer->getElement(i).getPairOfCards().second.getColor() << endl;
        cout << ListOfPlayer->getElement(i).getAbilityCard().getAbilityName() << endl;  
    }
}