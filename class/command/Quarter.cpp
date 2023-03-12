#include "Quarter.hpp"
#include <iostream>

//======== Quarter ========
Quarter::Quarter() : abilityCommand("ability", "quarter", List<Player>(10)){

}   

Quarter::Quarter(string type, string name,  List<Player> listPlayer) : abilityCommand(type, name, listPlayer){

}   

Quarter::Quarter(const Quarter& x ) : abilityCommand(x){

}   

Quarter& Quarter::operator=(const Quarter& X){

} 

Quarter::~Quarter(){
    abilityCommand::~abilityCommand();
}    

void Quarter::execute(int prize, Round round) {
    if (prize >= 4) {
        cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUARTER! Point hadiah turun dari " << prize;
        prize *= 0.25; 
        cout << " menjadi " << prize << endl;
    } else if (prize == 2) {
        cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUARTER! Sayangnya point hadiah hanya turun dari " << prize;
        prize *= 0.5; 
        cout << " menjadi " << prize << endl;
    } else {
        cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUARTER! Sayangnya hadiah sudah mencapai angka 1." << endl;
        cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
    }
}

bool Quarter::continueToNextPlayer(){
    return true;
}