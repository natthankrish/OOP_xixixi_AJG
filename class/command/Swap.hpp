#ifndef _SWAP_HPP_
#define _SWAP_HPP_
#include "AbilityCommand.hpp"

class Swap : AbilityCommand {
    public:
        Swap(string, string);             // user defined ctor

        void execute();
        bool continueToNextPlayer();
};

#endif