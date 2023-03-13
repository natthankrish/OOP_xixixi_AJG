#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_
#include "AbilityCommand.hpp"
class Round;

class Quarter : public AbilityCommand {
    private:

    public:
        Quarter();                          // default ctor
        Quarter(string, string);            // user defined ctor
        Quarter(const Quarter&);            // cctor
        Quarter& operator=(const Quarter&); // assignment
        ~Quarter();                         //  dtor

        void execute(int, Round);
        bool continueToNextPlayer();

};

#endif