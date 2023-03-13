#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "AbilityCommand.hpp"

class Switch : AbilityCommand {
    public:
        Switch(string, string);             // user defined ctor

        void execute();
        bool continueToNextPlayer();
};

#endif