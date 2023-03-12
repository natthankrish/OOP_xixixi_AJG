#ifndef _NEXT_HPP_
#define _NEXT_HPP_
#include "OrdinaryCommand.hpp"
#include "../Round.hpp"

class Next : public ordinaryCommand {
    private:

    public:
        Next();                         // default ctor
        Next(string, string, List<Player>);           // user defined ctor
        Next(const Next&);              // cctor
        Next& operator=(const Next&);   // assignment
        ~Next();                        //  dtor

        void execute(Round, int);

};

#endif