#include <iostream>
#include "stack.h"

using namespace std;

int main(int argc, char *argv[]) {
    FixedCapacityStack<String> *s =  new FixedCapacityStack(100);
    string tmpString;
    while(cin>>tmpString) {
        if(tmpString != "-") {
            s->push(tmpString);
        }else if(s->isEmpty()) {
            cout<<s->pop();
        }
    }

    cout<<"(" <<s->size() << s->size() << " left on stack)"<<endl;
    return 0;
}
