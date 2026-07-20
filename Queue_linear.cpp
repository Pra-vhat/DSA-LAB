#include <iostream>
using namespace std;

/*
 * Linear Queue: enqueue, dequeue
 * Circular Queue: enqueue, dequeue
*/

#define MAX_SIZE 100

// removed from front
// inserted from rear

class Queue{
    public:
    int front = 0;
    int rear = -1;
    int arr[MAX_SIZE];

    void enqueue(int value){
        // Enqueue means inserts an element at the rear
        if(rear == MAX_SIZE - 1){
            cout << "Sorry, size is full!" << endl;
            return;
        }
        rear ++;
        arr[rear] = value;
    }

    void dequeue(){
        // Dequeue means delete and element at the front
        // the front pointer is always incremented, one of the major downsides of arary based queue implementation
        if(rear > front){
            front ++;
        }
    }

    void print(){
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main(){
    Queue myQueue;
    myQueue.enqueue(5); // 5
    myQueue.enqueue(6); // 5 6
    myQueue.enqueue(8); // 5 6 8
    myQueue.print();
    myQueue.enqueue(4); // 5 6 8 4
    myQueue.print();
    myQueue.dequeue();  // 6 8 4
    myQueue.print();
}