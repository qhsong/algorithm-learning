#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue<string> q;

    string tmpString;
    while(cin>>tmpString) {
        if(tmpString != "-") {
            q.enqueue(tmpString);
        }else if(!q.isEmpty()) {
            cout<<q.dequeue()<< " ";
        }
    }
    cout<<"( "<< q.size()<<" left on queue )";
    return 0;
}
