#include "Throw.hpp"
#include <iostream>

//======== Half ========
Throw::Throw(string type, string name) : OrdinaryCommand(type, name){
}   

void Throw::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx, CardsBank& cardsbank, bool& ascending, int& cardToPick) {
    vector<vector<int>> candidate;
    vector<int> throwCard;
    int i = 0;
    for (auto ptr = listPlayer[playeridx-1].getPlayerCard().begin(); ptr != listPlayer[playeridx-1].getPlayerCard().end(); ptr++) {
        if (ptr->getNumber() <= 13 & (ptr->getColor() == tablecard.Top().getColor() || ptr->getNumber() == tablecard.Top().getNumber())) {
            if (cardToPick == 0 || (ptr->getNumber() == 13 && tablecard.Top().getNumber() == 13)) {
                vector<int> temp;
                temp.push_back(i);
                auto ptr2 = listPlayer[playeridx-1].getPlayerCard().begin();
                int j = 0;
                int k = 0;
                while (ptr2 != listPlayer[playeridx-1].getPlayerCard().end()) {
                    if (ptr->getNumber() == ptr2->getNumber() && i != j) {
                        temp.push_back(j);
                        if (j > k) {
                            k = j;
                        } 
                    }
                    ptr2++;
                    j++;
                }
                if (k > i) {
                    ptr = listPlayer[playeridx-1].getPlayerCard().begin() + k;
                    i = k;
                }
                
                candidate.push_back(temp);
            }
        } else if (ptr->getNumber() == 14) {
            vector<int> temp;
            temp.push_back(i);
            int j = 0;
            while (ptr+1 != listPlayer[playeridx-1].getPlayerCard().end()) {
                ptr++;
                i++;
                if (ptr->getNumber() == listPlayer[playeridx-1].getPlayerCard().at(*(temp.begin())).getNumber()) {
                    temp.push_back(i);
                } else {
                    ptr--;
                    i--;
                    break;
                }
            }
            candidate.push_back(temp);
        } else if (ptr->getNumber() == 15) {
            if (cardToPick == 0) {
                vector<int> temp;
                temp.push_back(i);
                int j = 0;
                while (ptr+1 != listPlayer[playeridx-1].getPlayerCard().end()) {
                    ptr++;
                    i++;
                    if (ptr->getNumber() == listPlayer[playeridx-1].getPlayerCard().at(*(temp.begin())).getNumber()) {
                        temp.push_back(i);
                    } else {
                        ptr--;
                        i--;
                        break;
                    }
                }
                candidate.push_back(temp);
            }
        }
        i++;
        
    }

    if (candidate.size() == 0) {
        success= false;
        cout << "Kartu teratas: " << tablecard.Top() << endl;
        cout << "Kamu tidak mempunyai kartu yang sesuai, silahkan lakukan command PICK untuk mengambil kartu" << endl;
    } else {
        cout << "Kartu teratas: " << tablecard.Top() << " " << endl;
        i = 1;
        for (auto ptr = candidate.begin(); ptr != candidate.end(); ptr++) {
            cout << i << ". ";
            cout << listPlayer[playeridx-1].getPlayerCard().at(*(ptr->begin()));
            for (auto ptr2 = candidate.at(i-1).begin(); ptr2 != candidate.at(i-1).end(); ptr2++) {
                if (ptr2 != candidate.at(i-1).begin()) {
                    cout << ", " << listPlayer[playeridx-1].getPlayerCard().at(*(ptr2));
                }   
            }
            i++;
            cout << endl;
        }
        success = true;
        cout << "Pilih kartu (1-" << candidate.size() << "): ";
        int choice, choice2;;
        cin >> choice;
        if (listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber() <= 10) {
            if (candidate.at(choice-1).size() > 2) {
                for (int i = 1; i <= candidate.at(choice-1).size()-1; i++) {
                    cout << i << ". " << listPlayer[playeridx-1].getPlayerCard().at(candidate.at(choice-1).at(i)) << endl;
                }
                cout << "Pilih kartu yang diletakkan di atas (1-" << candidate.at(choice-1).size()-1 << "): ";
                cin >> choice2;
                candidate.at(choice-1).push_back(candidate.at(choice-1).at(choice2));
                candidate.at(choice-1).erase(candidate.at(choice-1).begin() + choice2);
            }

            vector<NumberCard> temp;
            for (auto ptr = candidate.at(choice-1).begin(); ptr != candidate.at(choice-1).end(); ptr++) {
                temp.push_back(listPlayer[playeridx-1].getPlayerCard().at(*(ptr)));
            }

            for (auto ptr = temp.begin(); ptr != temp.end(); ptr++) {
                tablecard + *ptr;
                listPlayer[playeridx-1] - *ptr;
                i++;
            }
        } else if (listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber() >= 11 && (listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber() <= 13)) {
            int num = listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber();
            if (candidate.at(choice-1).size() > 1) {
                cout << "Pilih banyak kartu (1-" << candidate.at(choice-1).size() << "): ";
                cin >> choice2;
                vector<NumberCard> temp;
                for (auto ptr = candidate.at(choice-1).begin(); ptr != candidate.at(choice-1).end(); ptr++) {
                    temp.push_back(listPlayer[playeridx-1].getPlayerCard().at(*(ptr)));
                }
                if (candidate.at(choice-1).size() > 2) {
                    cout << "Kartu 1 (wajib): " << listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())) << endl;
                    tablecard + listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                    listPlayer[playeridx-1] - listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                    cout << "List tersedia: " << endl;
                    for(int i = 0; i < choice2; i++) {
                        cout <<  i+1 << ". " << listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin() + i));
                    }
                    
                    cout << "Pilih sesuai urutan (semakin terakhir berada di posisi teratas): " << endl;
                    int choice3;
                    for(int i = 1; i < choice2; i++) {
                        cout << "Kartu " << i << ": ";
                        cin >> choice3;
                        tablecard + *(temp.begin() + choice3 -1);
                        listPlayer[playeridx-1] - *(temp.begin() + choice3 -1);
                    }
                } else {
                    for (int i = 0; i < choice2; i++) {
                        tablecard + *(temp.begin() + i);
                        listPlayer[playeridx-1] - *(temp.begin() + i);
                    }
                }
                
                if (num == 11 || num == 12) {
                    int count = 0;
                    for (int i = 0; i < listPlayer.getNeff(); i++) {
                        if (!listPlayer[i].gethaveWin()) {
                            count++;
                        }
                    }
                    if (count == 2) {
                        playeridx++;
                    } else {
                        if (num == 11) {
                            if (choice2 % 2 == 1) {
                                if (ascending) {
                                    ascending = false;
                                } else {
                                    ascending = true;
                                }
                                cout << "Alur permainan diubah!" << endl;
                            } else {
                                cout << "Alur permainan tetap seperti semula" << endl;
                            }
                        } else {
                            if (ascending) {
                                playeridx += choice2;
                            } else {
                                playeridx -= choice2;
                            }
                            for (int i = choice2-1; i >= 0; i--) {
                                cout << "----------------------------------------------------------" << endl;
                                if (ascending) {
                                    cout << "Giliran player " << (playeridx-i) % count << " (" << listPlayer[((playeridx-i) % count) - 1].getName() << ") dilewatkan!" << endl;
                                } else {
                                    cout << "Giliran player " << (playeridx+i) % count << " (" << listPlayer[((playeridx-i) % count) - 1].getName() << ") dilewatkan!" << endl;
                                }
                                
                            }
                        }
                    }
                } else {
                    cardToPick += choice2 * 2;
                }
            } else {
                tablecard + listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                listPlayer[playeridx-1] - listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                if (num == 13) {
                    cardToPick += 2;
                } else {
                    int count = 0;
                    for (int i = 0; i < listPlayer.getNeff(); i++) {
                        if (!listPlayer[i].gethaveWin()) {
                            count++;
                        }
                    }
                    if (count == 2) {
                        if (ascending) {
                            playeridx++;
                        } else {
                            playeridx--;
                        }
                    } else {
                        if (num == 11) {
                            if (ascending) {
                                ascending = false;
                            } else {
                                ascending = true;
                            }
                            cout << "Alur permainan diubah!" << endl;
                        } else {
                            if (ascending) {
                                playeridx++;
                                if (playeridx > count) {
                                    playeridx -= count;
                                }
                            } else {
                                playeridx--;
                                if (playeridx < 1) {
                                    playeridx += count;
                                }
                            }
                            cout << "----------------------------------------------------------" << endl;
                            cout << "Giliran player " << playeridx << " (" << listPlayer[playeridx-1].getName() << ") dilewatkan!" << endl;
                        }
                    }
                }
            }
        } else if (listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber() >= 14) {
            if (candidate.at(choice-1).size() > 1) {
                cout << "Pilih banyak kartu (1-" << candidate.at(choice-1).size() << "): ";
                cin >> choice2;
                if (listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber() == 14) {
                    cardToPick += choice2 * 4;
                }
                for(int i = 0; i < choice2; i++) {
                    tablecard + listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                    listPlayer[playeridx-1] - listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                }
            } else {
                if (listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin())).getNumber() == 14) {
                    cardToPick += 4;
                }
                tablecard + listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
                listPlayer[playeridx-1] - listPlayer[playeridx-1].getPlayerCard().at(*(candidate.at(choice-1).begin()));
            }
            cout << "Pilih warna:\n1. merah\n2. hijau\n3. biru\n4. kuning" << endl;
            cout << "Masukkan pilihan (1-4): ";
            cin >> choice2;
            tablecard.Top().setColor(choice2);
        }
    }
}

bool Throw::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    if (success) {
        return true;
    } else {
        return false;
    }
}