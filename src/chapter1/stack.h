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
    a=NULL;
}
/*
template <class T>
class ReverseArrayIterator {
private:
    int i;
    const T *a;
public:
    ReverseArrayIterator(const T *start, int N) { a = start; i = N;}
    bool hasNext() { return i>0;}
    T next() {return a[--i];}   //this can overload operator++, but we just use next to same as book. We can change it after learning std source code.
    void remove() {}
};
*/
template <class T>
class ResizingArrayStack {
public:
    ResizingArrayStack();
    bool isEmpty() { return N==0; }
    int size() {return N;}
    void push(T item);
    T pop();
    class ReverseArrayIterator {
    private:
        int i;
        T* start;
    public:
        ReverseArrayIterator(T *a, int N){
            start=a;
            i = N;
        }
        bool hasNext() {return i>0;}
        T next() {return start[--i];}
        void remove() {};
    };

    ReverseArrayIterator iterator() {
        return ReverseArrayIterator(a, N);
    }
private:
    void resize(int max);
    T *a;
    int N;
    int cap;
};

template <class T>
ResizingArrayStack<T>::ResizingArrayStack() {
    a = new T[1];
    N = 0;
    cap = 1;
}

template <class T>
void ResizingArrayStack<T>::resize(int max) {
    T *temp = new T[max];
    for(int i=0; i<N; i++) {
        temp[i] = a[i];
    }
    delete [] a;
    cap = max;
    a = temp;
}

template <class T>
void ResizingArrayStack<T>::push(T item) {
    if(N == cap) resize(2*cap);
    a[N++] = item;
}

template <class T>
T ResizingArrayStack<T>::pop() {
    T item = a[--N];
    if(N > 0 && N == cap/4) resize(cap/2);
    return item;
}

template <class T>
class Stack {
private:
    int N;
public:
    class Node {
    public:
        T item;
        Node *next;
    };
    bool isEmpty() { return first==NULL; }
    int size() { return N; }
    void push(T item) {
        Node* oldFirst = first;
        first = new Node();
        first->item = item;
        first->next = oldFirst;
        N++;
    }

    T pop() {
        T item = first->item;
        first = first->next;
        N--;
        return item;
    }
    ~Stack() {
        Node *p = first;
        while(first){
            p = first->next;
            delete first;
            first = p;
        }
    }
    Stack() {
        Node *first = NULL;
    }
private:
    Node *first;
};


#endif
