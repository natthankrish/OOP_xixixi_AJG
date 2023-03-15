#ifndef LISTOFTHING_HPP
#define LISTOFTHING_HPP

template <class T>
class List {
    private:
        T* buffer;
        int neff;
        int size;

    public:
        // friend ordinaryCommand;
        // friend abilityCommand;
        List(int);
        ~List();
        T getElement(int);
        bool isEmptyList();
        int getSize();
        int getNeff();
        void setElementAt(int, T);
        bool isElement(T);
        void insertFirst(T);
        void insertAt(T, int);
        T& operator[] (int index);
        void insertLast(T);
        void deleteFirst();
        void deleteLast();
        void deleteAt(int);
        T getMaxElement();
};

#include "ListOfThing.cpp"
#endif