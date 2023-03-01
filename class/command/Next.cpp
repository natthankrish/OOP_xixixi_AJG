#include "Next.hpp"
#include <iostream>

//======== Next ========
Next::Next() : ordinaryCommand("ordinary","next"){

}   

Next::Next(string type, string name) : ordinaryCommand(type, name){

}   

Next::Next(const Next& x ) : ordinaryCommand(x){

}   

Next& Next::operator=(const Next& X){

} 

Next::~Next(){
    ordinaryCommand::~ordinaryCommand();
}    

void Next::execute() {
    cout<<"Next execute\n";
}