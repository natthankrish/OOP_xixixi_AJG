#ifndef _HALF_HPP_
#define _HALF_HPP_
#include "OrdinaryCommand.hpp"
#include "Round.hpp"

class Half : public ordinaryCommand {
    private:

    public:
        Half();                         // default ctor
        Half(string, string, List<Player>);           // user defined ctor
        Half(const Half&);              // cctor
        Half& operator=(const Half&);   // assignment
        ~Half();                        //  dtor

        void execute(Round, int);

};

#endif