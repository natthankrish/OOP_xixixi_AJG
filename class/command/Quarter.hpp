#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_
#include "AbilityCommand.hpp"

class Quarter : public AbilityCommand {
    public:
        Quarter(string, string);            // user defined ctor

        void execute(int, Round);
        bool continueToNextPlayer();
};

#endif