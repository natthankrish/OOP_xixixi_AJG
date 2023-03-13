#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name) : OrdinaryCommand(type, name){

}

bool Help::continueToNextPlayer(){
    return false;
}

void Help::execute(int){
    cout << "PUSAT BANTUAN" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masih under construction" << endl;
}
bool Help::continueToNextPlayer(){
    return false;
}