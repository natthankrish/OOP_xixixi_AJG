#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

using namespace std;

class Command {
    private:
        string type;
        string name;
    
    public:
        Command();                          // default ctor
        Command(string, string);            // user defined ctor
        Command(const Command&);            // cctor
        Command& operator=(const Command&); // assignment
        ~Command();                         // dtor

        // getter
        string getType();
        string getName();

        // setter 
        void setType(string);
        void setName(string);
    
        virtual void execute();
};

class abilityCommand : Command {
    private:

    public:
        abilityCommand();                                   // default ctor
        abilityCommand(string, string);                     // user defined ctor
        abilityCommand(const abilityCommand&);              // cctor
        abilityCommand& operator=(const abilityCommand&);   // assignment
        ~abilityCommand();                                  //  dtor

        void execute();
};

class ordinaryCommand : Command {
    private:

    public:
        ordinaryCommand();                                  // default ctor
        ordinaryCommand(string, string);                    // user defined ctor
        ordinaryCommand(const ordinaryCommand&);            // cctor
        ordinaryCommand& operator=(const ordinaryCommand&); // assignment
        ~ordinaryCommand();                                 //  dtor

        void execute();

};

class Reverse : abilityCommand {
    private:

    public:
        Reverse();                          // default ctor
        Reverse(string, string);            // user defined ctor
        Reverse(const Reverse&);            // cctor
        Reverse& operator=(const Reverse&); // assignment
        ~Reverse();                         //  dtor

        void execute();

};
 
class Reroll :  abilityCommand {
    private:

    public:
        Reroll();                           // default ctor
        Reroll(string, string);             // user defined ctor
        Reroll(const Reroll&);              // cctor
        Reroll& operator=(const Reroll&);   // assignment
        ~Reroll();                          //  dtor

        void execute();

};

class Swap : abilityCommand {
    private:

    public:
        Swap();                           // default ctor
        Swap(string, string);             // user defined ctor
        Swap(const Swap&);              // cctor
        Swap& operator=(const Swap&);   // assignment
        ~Swap();                          //  dtor

        void execute();

};

class Switch : abilityCommand {
    private:

    public:
        Switch();                           // default ctor
        Switch(string, string);             // user defined ctor
        Switch(const Switch&);              // cctor
        Switch& operator=(const Switch&);   // assignment
        ~Switch();                          //  dtor

        void execute();

};

class Quadruple : abilityCommand {
    private:

    public:
        Quadruple();                            // default ctor
        Quadruple(string, string);              // user defined ctor
        Quadruple(const Quadruple&);            // cctor
        Quadruple& operator=(const Quadruple&); // assignment
        ~Quadruple();                           //  dtor

        void execute();

};

class Abilityless : abilityCommand {
    private:

    public:
        Abilityless();                              // default ctor
        Abilityless(string, string);                // user defined ctor
        Abilityless(const Abilityless&);            // cctor
        Abilityless& operator=(const Abilityless&); // assignment
        ~Abilityless();                             //  dtor

        void execute();

};

class Quarter : abilityCommand {
    private:

    public:
        Quarter();                          // default ctor
        Quarter(string, string);            // user defined ctor
        Quarter(const Quarter&);            // cctor
        Quarter& operator=(const Quarter&); // assignment
        ~Quarter();                         //  dtor

        void execute();

};

class Next : ordinaryCommand {
    private:

    public:
        Next();                         // default ctor
        Next(string, string);           // user defined ctor
        Next(const Next&);              // cctor
        Next& operator=(const Next&);   // assignment
        ~Next();                        //  dtor

        void execute();

};

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

class Half : ordinaryCommand {
    private:

    public:
        Half();                         // default ctor
        Half(string, string);           // user defined ctor
        Half(const Half&);              // cctor
        Half& operator=(const Half&);   // assignment
        ~Half();                        //  dtor

        void execute();

};
#endif