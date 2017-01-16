template <class T>
class Queue {
public:
    class Node {
    public:
        T item;
        Node *next;
    };
    Queue() {
        N=0;
        first = last = NULL;
    }

    bool isEmpty() {return N==0;}
    int size() {return N;}
    void enqueue(T item) {
        Node *oldlast = last;
        last = new Node();
        last->item = item;
        last->next = NULL;
        if(isEmpty()) {
            first = last;
        }else{
            oldlast->next = last;
        }
        N++;
    }

    T dequeue() {
        T item = first->item;
        first = first->next;
        if(isEmpty()) last = NULL;
        N--;
        return item;
    }
private:
    Node* first;
    Node* last;
    int N;

};
