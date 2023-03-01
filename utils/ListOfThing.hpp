#ifndef LISTOFTHING_HPP
#define LISTOFTHING_HPP

template <class T>
class List {
    private:
        T* buffer;
        int neff;
        int size;

    public:
        List(int);
        T getElement(int);
        bool isEmptyList();
        int getSize();
        void insertFirst(T);
        void insertAt(T, int);
        void insertLast(T);
        void deleteFirst();
        void deleteLast();
        void deleteAt(int);
        T getMaxElement();
};

#endif