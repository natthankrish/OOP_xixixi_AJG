#ifndef COMBINATION_HPP
#define COMBINATION_HPP

static const double MAX_VALUE = 2.0;

class Combination {
    protected: 
        static const double MAX_VALUE;
    public: 
        virtual double getValue() = 0;
        virtual double getCombo() = 0;
};

#endif


