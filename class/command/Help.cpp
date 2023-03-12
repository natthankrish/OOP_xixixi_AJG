#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name, List<Player> listPlayer) : ordinaryCommand(type, name, listPlayer){

}

bool Help::continueToNextPlayer(){
    return false;
}

void Help::execute(Round, int){
    cout << "PUSAT BANTUAN" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masih under construction" << endl;
}
bool Help::continueToNextPlayer(){
    return false;
}