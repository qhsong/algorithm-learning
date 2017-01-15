#include <iostream>
#include "stack.h"

using namespace std;

int main(int argc, char *argv[]) {
    Stack<string> *s =  new Stack<string>();
    string tmpString;
    while(cin>>tmpString) {
        if(tmpString != "-") {
            s->push(tmpString);
        }else if(!s->isEmpty()) {
            cout<<s->pop()<<" ";
        }
    }

    cout<<"(" <<s->size() << " left on stack)"<<endl;
    delete s;
    return 0;
}
