#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_
#include "AbilityCommand.hpp"

class Reverse : public AbilityCommand {
    public:
        Reverse(string, string);            // user defined ctor

        void execute();
        bool continueToNextPlayer();
};

#endif