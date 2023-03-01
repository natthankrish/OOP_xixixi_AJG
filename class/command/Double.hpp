#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_
#include "OrdinaryCommand.hpp"

class Double : ordinaryCommand {
    private:

    public:
        Double();                           // default ctor
        Double(string, string);             // user defined ctor
        Double(const Double&);              // cctor
        Double& operator=(const Double&);   // assignment
        ~Double();                          //  dtor

        void execute();

};

#endif