#include "ChangeCard.hpp"
#include <iostream> 
#include <fstream>
using namespace std;

ChangeCard::ChangeCard(string type, string name) : OrdinaryCommand("ordinary", "changenum"){   

}

bool ChangeCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void ChangeCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    string filename;
    cout << "Masukkan nama file card player dengan ekstensi .txt: ";
    cin >> filename;

    string path = "test/";
    ifstream infile(path + filename); // sementara
    while (infile.fail()) {
        cout << "Failed to open file: " << path << filename << endl;
        cout << "Masukkan ulang nama file card player dengan ekstensi .txt: ";
        cin >> filename;
        infile = ifstream(path + filename); // sementara
    } 
    
    string word;
    int num;
    int count = 0;

    // cout << "Cardsbank size: " << cardsbank.getElement().size() << endl;

    vector<NumberCard> tempp;
    for (int i = 0; i < 14*2; i++) {
        if (infile >> word) {
            if (isNum(word)) {
                num = stringToInt(word);
            } else {
                // cout << num << " " << word << endl;
                tempp.push_back(NumberCard(num, word));
            }
        } else {
            throw PlayerCardDoNotMatch();
        }
    } 
    // saving cards bank cards
    vector<NumberCard> oldcardsbank;
    for (int i = 0; i < cardsbank.getElement().size(); i++) {
        oldcardsbank.push_back(cardsbank.getElementAt(i));
    }

    // saving the player cards
    vector<NumberCard> oldplayercards;
    // taking all of the number cards from player
    while (count < 7) {
        if (listPlayer.getElement(count).getPairOfCards().first != NumberCard() && listPlayer.getElement(count).getPairOfCards().second != NumberCard()) {
            // cout << "Masuk taking all of the number cards from player, kartu number tidak kosong" << endl; 
            oldplayercards.push_back(listPlayer[count].getPairOfCards().first);
            oldplayercards.push_back(listPlayer[count].getPairOfCards().second);
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

    // cout << "temp size: " << tempp.size() << endl;
    // cardsbank.seeCard();
    // bagi ulang dengan spesifikasi dari file
    count = 0;
    int counttemp = 0;
    while (count < 7) {
        // cout << temp.getNumber() << " " << temp.getColor() << endl
        for (int i = 0; i < 2; i++) {
            listPlayer[count] + tempp[counttemp];
            // cout << listPlayer.getElement(count).getPairOfCards().first.getNumber() << listPlayer.getElement(count).getPairOfCards().first.getColor() << endl;
            try {
                cardsbank - tempp[counttemp];
            } catch (CardNotFoundException e) {
                // clearing cards bank 
                while (cardsbank.getElement().size() > 0) {
                    cardsbank - cardsbank.getElementAt(0);
                }
                // cout << cardsbank.getElement().size() << endl;
                // assigning it back to the old cards bank
                for (int i = 0; i < oldcardsbank.size(); i++) {
                    cardsbank + oldcardsbank[i];
                }
                // cout << "size now: " << cardsbank.getElement().size() << endl;

                // clearing player card
                int countplayer = 0;

                for (int i = 0; i < 7; i++) {
                    for (int i = 0; i < 2; i++) {
                        listPlayer[countplayer] - listPlayer[countplayer].getPairOfCards().first;
                        listPlayer[countplayer] - listPlayer[countplayer].getPairOfCards().second;
                    }
                    countplayer++;
                }

                countplayer = 0;
                for (int i = 0; i < 7; i++) {
                    for (int i = 0; i < 2; i++) {
                        listPlayer[countplayer] + oldplayercards[countplayer];
                    }
                    countplayer++;
                }
                // cout << listPlayer[0].getPairOfCards().first.getNumber() << " " << listPlayer[0].getPairOfCards().first.getColor() << endl; 
                throw ChangePlayerCardFailed();

            }
            counttemp++;
        }
        count++;
    }

    // cout << "Count temp" << counttemp << endl;
    // cout << endl;
    infile.close();

    cout << "Masukkan nama file ability card player dengan ekstensi .txt: ";
    cin >> filename;

    ifstream infile2(path + filename); // sementara
    while (infile2.fail()) {
        cout << "Failed to open file: " << path << filename << endl;
        cout << "Masukkan ulang nama file ability card player dengan ekstensi .txt: ";
        cin >> filename;
        infile2 = ifstream(path + filename);
    } 

    // taking all of the ability cards from player
    bool hasAbilityCard = false;
    count = 0;
    while (count < 7) {
        if (listPlayer.getElement(count).getAbilityCard() != AbilityCard()) {
            // cout << "Masuk taking all of the ability cards from player, kartu ability tidak kosong" << endl; 
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
            // cout << word << endl;
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

    vector<NumberCard> oldcardsbank2;
    for (int i = 0; i < cardsbank.getElement().size(); i++) {
        oldcardsbank2.push_back(cardsbank.getElementAt(i));
    }
    // cout << "Cardsbank size3: " << cardsbank.getElement().size() << endl;
    // penggantian table card
    cout << "Masukkan nama file table card dengan ekstensi .txt: ";
    cin >> filename;

    ifstream infile3(path + filename); // sementara
    while (infile3.fail()) {
        cout << "Failed to open file: " << path << filename << endl;
        cout << "Masukkan ulang nama file table card dengan ekstensi .txt: ";
        cin >> filename;
        infile3 = ifstream(path + filename);
    }
   
    count = 0;
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
            throw TableCardDoNotMatch();
        }
    } 

    // cout << "Cardsbank size: " << cardsbank.getElement().size() << endl;
    // for (int i = 0; i < 5; i++) {
    //     try {
    //         cardsbank - temp[i];
    //     } catch (CardNotFoundException e) {
    //         // returning the cards back to the cards bank
    //         for (int j = 0; j < i-1; j++) {
    //             cardsbank + temp[j];
    //         }
    //         throw ChangeTableCardFailed();
    //     }
    // }

    // cout << "Cardsbank size: " << cardsbank.getElement().size() << endl;
    // all cards from the input file are found in the cards bank
    // placing the cards from the input file to the table card
    for (int i = 0; i < countTableCard; i++) {
        try {
            cardsbank - temp[i];
        } catch (CardNotFoundException e) {
            while (cardsbank.getElement().size() > 0) {
                cardsbank - cardsbank.getElementAt(0);
            }
            // cout << cardsbank.getElement().size() << endl;
            // assigning it back to the old cards bank
            for (int i = 0; i < oldcardsbank2.size(); i++) {
                cardsbank + oldcardsbank2[i];
            }
            // cout << "size now: " << cardsbank.getElement().size() << endl;
            // clearing table card 
            // cout << " table size now: " << tablecard.getCard().size() << endl;
            while (tablecard.getCard().size() > 0) {
                // cout << "something" << endl;
                tablecard - tablecard.getCard()[0];
            }

            for (int i = 0; i < temp0.size(); i++) {
                // cout << "something2" << endl;
                tablecard + temp0[i];
            }

            // cout << "TABLE CARD" << tablecard.getCard()[0].getNumber() << " " << tablecard.getCard()[0].getColor() << endl;
            throw ChangeTableCardFailed();
        }
        tablecard + temp[i];
    }

    // placing the rest of the table card
    for (int i = 4; i >= countTableCard; i--) {
        // placing the rest of the cards on top of the cardsbank
        try {
            cardsbank - temp[i];
        } catch (CardNotFoundException e) {
            while (cardsbank.getElement().size() > 0) {
                cardsbank - cardsbank.getElementAt(0);
            }
            // cout << cardsbank.getElement().size() << endl;
            // assigning it back to the old cards bank
            for (int i = 0; i < oldcardsbank2.size(); i++) {
                cardsbank + oldcardsbank2[i];
            }
            // cout << "size now: " << cardsbank.getElement().size() << endl;
            // clearing table card 
            while (tablecard.getCard().size() > 0) {
                // cout << "something" << endl;
                tablecard - tablecard.getCard()[0];
            }

            for (int i = 0; i < temp0.size(); i++) {
                tablecard + temp0[i];
            }
            throw ChangeTableCardFailed();
        }
        cardsbank + temp[i];
    }
    

    infile3.close();
    // checking
    // for (int i = 0; i < countTableCard; i++) {
    //     cout << tablecard.getCard()[i].getNumber() << " " 
    //     << tablecard.getCard()[i].getColor() << endl;
    // }
}

int ChangeCard::stringToInt(string word) {
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

bool ChangeCard::isNum(string word) {
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


//     TableCard tablecard;
//     long long int prize = 0;
//     // bagi ability 
//     // checking
//     // cardsbank.bagiKartu(*ListOfPlayer);

//     // bagi kartu untuk player
//     bool something = true;

//     ChangeCard change("something", "something");
//     try {
//         change.execute(tablecard, *ListOfPlayer, 0, prize, cardsbank, abilitybank, something);
//     } catch (TableCardDoNotMatch e) {
//         cout << e.what() << endl; 
//     } catch (PlayerCardDoNotMatch e) {
//         cout << e.what() << endl; 
//     } catch (ChangePlayerCardFailed e) {
//         cout << e.what() << endl; 
//     } catch (ChangeTableCardFailed e) {
//         cout << e.what() << endl; 
//     }
//     for (int i = 0; i < 7; i++) {
//         cout << i << " " << ListOfPlayer->getElement(i).getPairOfCards().first.getNumber() << " " 
//         << ListOfPlayer->getElement(i).getPairOfCards().first.getColor() << endl;
//         cout << i << " " << ListOfPlayer->getElement(i).getPairOfCards().second.getNumber() << " " 
//         << ListOfPlayer->getElement(i).getPairOfCards().second.getColor() << endl;
//     }

//     for (int i = 0 ; i < abilitybank.getElement().size(); i++) {
//         cout << abilitybank.getElementAt(i).getAbilityName() << endl;
//     }

//     int count = 37;
//     for (int i = 0; i < 5; i++) {
//         cout << cardsbank.getElementAt(count).getNumber() << cardsbank.getElementAt(count).getColor() << endl;
//         count--;
//     }

// }