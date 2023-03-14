#include "ChangeTableCard.hpp"
#include <iostream> 
#include <fstream>
using namespace std;

ChangeTableCard::ChangeTableCard(string type, string name) : OrdinaryCommand("ordinary", "changenum"){   

}

bool ChangeTableCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void ChangeTableCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
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

    // skipping the player number cards and ability cards
    while (count < 36 && infile >> word) {
        count++;
    }

    // taking all the cards back from the table to cards bank
    int countTableCard = tablecard.getCard().size();
    while (tablecard.getCard().size() > 0) {
        // cout << "Error?" << endl;
        // cout << tablecard.getCard()[0].getNumber() << tablecard.getCard()[0].getColor() << endl; 
        NumberCard temp(tablecard.getCard()[0].getNumber(), tablecard.getCard()[0].getColor());
        tablecard - temp;
        cardsbank + temp;
    }

    // placing the cards from the input file to the table card
    count = 0;
    while (count < countTableCard * 2 && infile >> word) {
        if (isNum(word)) {
            num = stringToInt(word);
        } else {
            cout << num << " " << word << endl;
            NumberCard temp(num, word);
            tablecard + temp;
            cardsbank - temp;
        }
        count++;
    }    
    

    infile.close();
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
//     ChangeTableCard change("tablecard", "card");
//     int prize = 0;
//     NumberCard temp(1,"merah");
//     NumberCard temp2(2,"merah");
//     NumberCard temp3(3,"merah");
//     tablecard + temp;
//     tablecard + temp2;
//     tablecard + temp3;

//     for (int i = 0; i < tablecard.getCard().size(); i++) {
//         cout << tablecard.getCard()[i].getNumber() << " " << tablecard.getCard()[i].getColor() << endl;
//     }
//     change.execute(tablecard, *ListOfPlayer, 0, prize, cardsbank, abilitybank);
// }