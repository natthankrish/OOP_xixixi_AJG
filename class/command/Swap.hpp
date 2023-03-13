#ifndef _SWAP_HPP_
#define _SWAP_HPP_
#include "AbilityCommand.hpp"

class Swap : abilityCommand {
    private:

    public:
        Swap();                           // default ctor
        Swap(string, string);             // user defined ctor
        Swap(const Swap&);              // cctor
        Swap& operator=(const Swap&);   // assignment
        ~Swap();                          //  dtor

        void execute();
        bool continueToNextPlayer();

};

#endif