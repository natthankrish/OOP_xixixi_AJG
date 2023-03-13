#include "Next.hpp"
#include <iostream>

//======== Next ========
Next::Next() : OrdinaryCommand("ordinary","next"){

}   

Next::Next(string type, string name) : OrdinaryCommand(type, name){

}   

Next::Next(const Next& x ) : OrdinaryCommand(x){

}   

Next& Next::operator=(const Next& X){

} 

Next::~Next(){
    OrdinaryCommand::~OrdinaryCommand();
}    

void Next::execute(int prize) {
    cout << "Giliran dilanjut ke player selanjutnya." << endl;
}

bool Next::continueToNextPlayer(){
    return true;
}