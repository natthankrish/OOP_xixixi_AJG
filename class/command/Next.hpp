#ifndef _NEXT_HPP_
#define _NEXT_HPP_
#include "OrdinaryCommand.hpp"
#include "../Round.hpp"

class Next : public ordinaryCommand {
    private:

    public:
        Next();                         // default ctor
        Next(string, string);           // user defined ctor
        Next(const Next&);              // cctor
        Next& operator=(const Next&);   // assignment
        ~Next();                        //  dtor

        void execute(List<Player>&, int, int&);
        bool continueToNextPlayer();


};

#endif