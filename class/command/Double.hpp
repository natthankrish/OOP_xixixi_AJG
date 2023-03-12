#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_
#include "OrdinaryCommand.hpp"
class Round;

class Double : public ordinaryCommand {
    private:

    public:
        Double();                           // default ctor
        Double(string, string, List<Player>);             // user defined ctor
        Double(const Double&);              // cctor
        Double& operator=(const Double&);   // assignment
        ~Double();                          //  dtor

        void execute(int, Round);
        bool continueToNextPlayer();


};

#endif