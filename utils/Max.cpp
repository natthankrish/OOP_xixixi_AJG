#include "Max.hpp"

template <class T>
T getMaxList(List<T> listplayer) {
    T max = listplayer.getElementAt(0);
    for (int i = 1; i < listplayer.getNeff(); i++) {
        if (listplayer.getElementAt(i) > max) {
            max = listplayer.getElementAt(i);
        }
    }
    return max;
}

template <class T>
T getMaxVector(vector<T> vec) {
    T max = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}