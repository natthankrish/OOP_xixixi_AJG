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
        int getSize();
        void insertFirst(T);
        void insertAt(T);
        void insertLast(T);
        void deleteFirst()
        void deleteLast();
        void deleteAt(int);
        T getMaxElement();
};

#endif