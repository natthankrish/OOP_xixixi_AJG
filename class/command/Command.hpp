#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "../inventory/Player.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

using namespace std;

class Command {
    private:
        string type;
        string name;
    
    public:
        Command();                          // default ctor
        Command(string, string);            // user defined ctor
        Command(const Command&);            // cctor
        Command& operator=(const Command&); // assignment
        ~Command();                         // dtor

        // getter
        string getType();
        string getName();

        // setter 
        void setType(string);
        void setName(string);
    
        virtual void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);

        virtual bool continueToNextPlayer();
};

#endif