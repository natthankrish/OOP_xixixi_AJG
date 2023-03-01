#include "Command.hpp"
#include <iostream>

using namespace std;

//======== command ========
Command::Command(){
    
}

Command::Command(string type, string name): type(type), name(name) {
}

Command::Command(const Command& x): type(x.type), name(x.name){

}

Command& Command::operator=(const Command& x){
    setType(x.type);
    setName(x.name);

    return *this;
}

Command::~Command(){}

string Command::getType() {
    return this->type;
}

string Command::getName() {
    return this->name;
}

void Command::setType(string type) {
    this->type = type;
}

void Command::setName(string name) {
    this->name = name;
}

void Command::execute() {
    cout << "execute Command\n";
}

//======== abilityCommand ========
abilityCommand::abilityCommand() : Command(){

}

abilityCommand::abilityCommand(string type, string name) : Command(type, name) {

}

abilityCommand::abilityCommand(const abilityCommand& x) : Command(x) {

}

abilityCommand& abilityCommand::operator=(const abilityCommand& x) {

}

abilityCommand::~abilityCommand() {
    Command::~Command();
}

void abilityCommand::execute() {
    cout<<"abilityCommand execute\n";
}

//======== ordinaryCommand ========
ordinaryCommand::ordinaryCommand() : Command(){

}  

ordinaryCommand::ordinaryCommand(string type, string name) : Command(type, name){

}  

ordinaryCommand::ordinaryCommand(const ordinaryCommand& x ) : Command(x){

}   

ordinaryCommand& ordinaryCommand::operator=(const ordinaryCommand& X){

} 

ordinaryCommand::~ordinaryCommand(){
    Command::~Command();
}                               

void ordinaryCommand::execute() {
    cout<<"ordinaryCommand execute\n";
}

//======== Reverse ========
Reverse::Reverse() : abilityCommand(){

}   

Reverse::Reverse(string type, string name) : abilityCommand(type, name){

}   

Reverse::Reverse(const Reverse& x ) : abilityCommand(x){

}   

Reverse& Reverse::operator=(const Reverse& X){

} 

Reverse::~Reverse(){
    abilityCommand::~abilityCommand();
}    

void Reverse::execute() {
    cout<<"Reverse execute\n";
}

//======== Reroll ========
Reroll::Reroll() : abilityCommand(){

}   

Reroll::Reroll(string type, string name) : abilityCommand(type, name){

}   

Reroll::Reroll(const Reroll& x ) : abilityCommand(x){

}   

Reroll& Reroll::operator=(const Reroll& X){

} 

Reroll::~Reroll(){
    abilityCommand::~abilityCommand();
}    

void Reroll::execute() {
    cout<<"Reroll execute\n";
}

//======== Swap ========
Swap::Swap() : abilityCommand(){

}   

Swap::Swap(string type, string name) : abilityCommand(type, name){

}   

Swap::Swap(const Swap& x ) : abilityCommand(x){

}   

Swap& Swap::operator=(const Swap& X){

} 

Swap::~Swap(){
    abilityCommand::~abilityCommand();
}    

void Swap::execute() {
    cout<<"Swap execute\n";
}

//======== Switch ========
Switch::Switch() : abilityCommand(){

}   

Switch::Switch(string type, string name) : abilityCommand(type, name){

}   

Switch::Switch(const Switch& x ) : abilityCommand(x){

}   

Switch& Switch::operator=(const Switch& X){

} 

Switch::~Switch(){
    abilityCommand::~abilityCommand();
}    

void Switch::execute() {
    cout<<"Switch execute\n";
}

//======== Quadruple ========
Quadruple::Quadruple() : abilityCommand(){

}   

Quadruple::Quadruple(string type, string name) : abilityCommand(type, name){

}   

Quadruple::Quadruple(const Quadruple& x ) : abilityCommand(x){

}   

Quadruple& Quadruple::operator=(const Quadruple& X){

} 

Quadruple::~Quadruple(){
    abilityCommand::~abilityCommand();
}    

void Quadruple::execute() {
    cout<<"Quadruple execute\n";
}

//======== Abilityless ========
Abilityless::Abilityless() : abilityCommand(){

}   

Abilityless::Abilityless(string type, string name) : abilityCommand(type, name){

}   

Abilityless::Abilityless(const Abilityless& x ) : abilityCommand(x){

}   

Abilityless& Abilityless::operator=(const Abilityless& X){

} 

Abilityless::~Abilityless(){
    abilityCommand::~abilityCommand();
}    

void Abilityless::execute() {
    cout<<"Abilityless execute\n";
}

//======== Quarter ========
Quarter::Quarter() : abilityCommand(){

}   

Quarter::Quarter(string type, string name) : abilityCommand(type, name){

}   

Quarter::Quarter(const Quarter& x ) : abilityCommand(x){

}   

Quarter& Quarter::operator=(const Quarter& X){

} 

Quarter::~Quarter(){
    abilityCommand::~abilityCommand();
}    

void Quarter::execute() {
    cout<<"Quarter execute\n";
}

//======== Next ========
Next::Next() : ordinaryCommand(){

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

//======== Double ========
Double::Double() : ordinaryCommand(){

}   

Double::Double(string type, string name) : ordinaryCommand(type, name){

}   

Double::Double(const Double& x ) : ordinaryCommand(x){

}   

Double& Double::operator=(const Double& X){

} 

Double::~Double(){
    ordinaryCommand::~abilityCommand();
}    

void Double::execute() {
    cout<<"Double execute\n";
}

//======== Half ========
Half::Half() : ordinaryCommand(){

}   

Half::Half(string type, string name) : ordinaryCommand(type, name){

}   

Half::Half(const Half& x ) : ordinaryCommand(x){

}   

Half& Half::operator=(const Half& X){

} 

Half::~Half(){
    ordinaryCommand::~abilityCommand();
}    

void Half::execute() {
    cout<<"Half execute\n";
}


