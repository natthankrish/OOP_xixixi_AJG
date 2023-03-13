#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name) : ordinaryCommand(type, name){

}

bool Help::continueToNextPlayer(){
    return false;
}

void Help::execute(List<Player>& listPlayer, int playeridx, int& prize){
    cout << "PUSAT BANTUAN" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masih under construction" << endl;
    cout << "---------------------------------------" << endl;
}
