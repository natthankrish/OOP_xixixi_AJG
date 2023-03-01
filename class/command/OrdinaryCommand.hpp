#ifndef _ORDINARY_COMMAND_HPP
#define _ORDINARY_COMMAND_HPP
#include "Command.hpp"

class ordinaryCommand : public Command {
    private:

    public:
        ordinaryCommand();                                  // default ctor
        ordinaryCommand(string, string);                    // user defined ctor
        ordinaryCommand(const ordinaryCommand&);            // cctor
        ordinaryCommand& operator=(const ordinaryCommand&); // assignment
        ~ordinaryCommand();                                 //  dtor

        void execute();

};


#endif