#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    ResizingArrayStack<int> s;
    for(int i=0; i<100; i++) {
        s.push(i);
    }

    ResizingArrayStack<int>::ReverseArrayIterator it = s.iterator();
    while(it.hasNext()) {
        cout<<it.next()<<" ";
    }
    cout<<endl;
    return 0;
}
