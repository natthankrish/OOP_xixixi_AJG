#include "Half.hpp"
#include "../Round.hpp"
#include <iostream>

//======== Half ========
Half::Half() : ordinaryCommand("ordinary", "double", List<Player>(10)){

}   

Half::Half(string type, string name, List<Player> listPlayer) : ordinaryCommand(type, name, listPlayer){

}   

Half::Half(const Half& x ) : ordinaryCommand(x){

}   

Half& Half::operator=(const Half& X){

} 

Half::~Half(){
    ordinaryCommand::~abilityCommand();
}    

void Half::execute(int prize, Round round) {
    if (prize != 1) {
        cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan HALF! Point hadiah turun dari " << prize;
        prize *= 0.5; 
        cout << " menjadi " << prize << endl;
    } else {
        cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan HALF! Sayangnya hadiah sudah mencapai angka 1." << endl;
        cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
    }
}
bool Half::continueToNextPlayer(){
    return true;
}