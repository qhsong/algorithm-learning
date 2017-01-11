#include "stack.h"

FixedCapcityStackOfStrings::FixedCapcityStackOfStrings(int cap) {
    a = new T[cap];
}

bool FixedCapcityStackOfStrings::isEmpty() {
    return N==0;
}

void push(T &item) {
    a[N++] = item;
}

int size() {
    return N;
}

T pop() {
    return T[--N];
}


FixedCapcityStackOfStrings:~FixedCapcityStackOfStrings() {
    delete [] a;
}
