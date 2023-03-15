#include "ListOfThing.hpp"
template <class T>
List<T>::List(int size): size(size), neff(0) {
    this->buffer = new T[size];
}

template <class T>
List<T>::~List() {
    delete[] this->buffer;
}

template <class T>
T List<T>::getElement(int index) {
    return this->buffer[index];
}
template <class T>
void List<T>::setElementAt(int index, T element) {
    this->buffer[index] = element;
}

template <class T>
bool List<T>::isEmptyList() {
    return this->neff = 0;
}

template <class T>
int List<T>::getSize() {
    return this->size;
}

template <class T>
int List<T>::getNeff() {
    return this->neff;
}

template <class T>
bool List<T>::isElement(T item) {
    for (int i = 0; i < this->neff; i++) {
        if (item == this->buffer[i]) {
            return true;
        }
    }
    return false;
}

template <class T>
void List<T>::insertFirst(T item) {
// Insert item sebagai elemen pertama dan menggeser item yang sudah ada 
    if (isEmptyList()) {
        this->buffer[neff] = item;
    } else {
        for (int i = 1; i < neff + 1; i++) {
            this->buffer[i] = this->buffer[i-1];
        }
        this->buffer[0] = item;
    }
    this->neff++;
}

template <class T>
void List<T>::insertAt(T item, int index) {
// Kondisi awal list tidak empty
    if (!isEmptyList()) {
        for (int i = index; i < this->neff + 1; i++) {
            this->buffer[i+1] = this->buffer[i];
        }
        this->buffer[index] = item;
    }
    this->neff++;
}

template <class T>
void List<T>::insertLast(T item) {
    this->buffer[neff] = item;
    this->neff++;
}

template <class T>
void List<T>::deleteFirst() {
    if (!isEmptyList()) {
        if (this->neff == 1) {
            this->neff = 0;
        } else {
            for (int i = 0; i < this->neff-1; i++) {
                this->buffer[i] = this->buffer[i+1];
            }
            this->neff--;
        }
    }
}

template <class T>
void List<T>::deleteLast() {
    if (!isEmptyList()) {
        this->neff--;
    }
}

template <class T>
void List<T>::deleteAt(int index) {
    if (!isEmptyList()) {
        for (int i = index; i < this->neff - 1; i++) {
            this->buffer[i] = this->buffer[i+1];
        }
        this->neff--;
    }
}

template <class T>
T& List<T>::operator[] (int index) {
    return this->buffer[index];
}

template <class T>
T List<T>::getElementAt(int index) {
    return this->buffer[index];
}

template <class T>
T List<T>::getMaxElement() {
    if (!isEmptyList()) {
        if (this->neff == 1) {
            return this->buffer[0];
        } else {
            T max = this->buffer[0];
            for (int i = 1; i < this->neff; i++) {
                if (this->buffer[i] > max) {
                    max = this->buffer[i];
                }
            }
            return max;
        }
    }
    return 0;
}