#include <iostream>
using namespace std;

/*
 * What is the difference between linearQueue and circularQueue?
-> Only the index computation of front and rear is different
*/

# define MAX_SIZE 5

class circularQueue{
    public:
    int front;
    int rear;
    int size;
    int arr[MAX_SIZE];

    public:
    circularQueue(){
        front = 0;
        rear = -1;
        size = 0;
    }
    void enqueue(int value){
        if(!isFull()){
            rear = ++rear % MAX_SIZE;
            arr[rear] = value;
            size++;
        }else{
            cout << "Queue Overflow!" << endl;
        }
    }
    void dequeue(){
        if(!isEmpty()){
            front = ++front % MAX_SIZE;
            size--;
        }else{
            cout << "Queue Underflow!" << endl;
        }
    }

    void print(){

        // cout << "Original Array" << endl;
        // for(int i = 0; i < MAX_SIZE; i++){
        //     cout << arr[i] << " ";
        // }cout << endl;

        for(int index = front, i = 0; i < size; i++, index = (++index) % MAX_SIZE){
            cout << arr[index] << " ";
        }cout << "\t\tFront " << front << " Rear " << rear << endl;
        cout << endl;
    }
    bool isEmpty(){
        return (size == 0);
    }
    bool isFull(){
        return (size == MAX_SIZE);
    }

};


int main(){
    circularQueue myQueue; //           Front   Rear
    myQueue.enqueue(5); // 5               0    0
    myQueue.print();
    myQueue.enqueue(6); // 5 6             0    1
    myQueue.print();
    myQueue.enqueue(8); // 5 6 8           0    2
    myQueue.print();
    myQueue.enqueue(4); // 5 6 8 4         0    3
    myQueue.print();
    myQueue.dequeue();  // (5) 6 8 4       1   3
    myQueue.print();
    myQueue.dequeue(); // (5) (6) 8 4      1    3
    myQueue.dequeue(); // (5) (6) (8) 4    2    3

    // let's make the rear 4, and then perform enqueue
    // so we may verify if the index computation properly works
    //                                           Front   Rear
    myQueue.enqueue(9); // (5) (6) (8) 4 9          3       4
    myQueue.enqueue(7); // 7 (6) (8) 4 9            3       0
    myQueue.print();

    // OK. Works as intended.
}