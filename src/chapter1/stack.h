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
class FixedCapcityStackOfStrings{
public:
    FixedCapcityStackOfStrings(int cap);
    void push(T &item);
    T pop();
    bool isEmpty();
    int size();
    ~FixedCapcityStackOfStrings();
private:
    T *a;
    int N;

};
