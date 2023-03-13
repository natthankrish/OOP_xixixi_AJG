#ifndef _HALF_HPP_
#define _HALF_HPP_
#include "OrdinaryCommand.hpp"
class Round;

class Half : public OrdinaryCommand {
    private:

    public:
        Half();                         // default ctor
        Half(string, string);           // user defined ctor
        Half(const Half&);              // cctor
        Half& operator=(const Half&);   // assignment
        ~Half();                        //  dtor

        void execute(int, Round);
        bool continueToNextPlayer();

};

#endif