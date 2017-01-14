#ifndef __CHAPTER1_STACK_H
#define __CHAPTER1_STACK_H
#include "iterable.h"

/*
template <class T>
class Bag<T> : public Iterable<T> {
    Bag();
    void add(T& item);
    bool isEmpty();
    int size();
}

*/
template <class T>
class FixedCapacityStack{
public:
    FixedCapacityStack(int cap);
    void push(T item);
    T pop();
    bool isEmpty();
    int size();
    ~FixedCapacityStack();
private:
    T *a;
    int N;

};

template <class T>
FixedCapacityStack<T>::FixedCapacityStack(int cap) {
    a = new T[cap];
}

template <class T>
bool FixedCapacityStack<T>::isEmpty() {
    return N==0;
}

template <class T>
void FixedCapacityStack<T>::push(T item) {
    a[N++] = item;
}

template <class T>
int FixedCapacityStack<T>::size() {
    return N;
}

template <class T>
T FixedCapacityStack<T>::pop() {
    return a[--N];
}


template <class T>
FixedCapacityStack<T>::~FixedCapacityStack() {
    delete [] a;
}
#endif
