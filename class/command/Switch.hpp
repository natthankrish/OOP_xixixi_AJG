#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "AbilityCommand.hpp"

class Switch : abilityCommand {
    private:

    public:
        Switch();                           // default ctor
        Switch(string, string);             // user defined ctor
        Switch(const Switch&);              // cctor
        Switch& operator=(const Switch&);   // assignment
        ~Switch();                          //  dtor

        void execute();
        bool continueToNextPlayer();


};

#endif