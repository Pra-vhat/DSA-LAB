#include <iostream>
#include <stdlib.h>
using namespace std;

/*
 * Stack Operations
 * pop() - removes the top element
 * push() - insert an element at the top
 * peek() - return the top value
 * size() - return the size of the stack
 * capacity() - return the capacity of the stack
 * empty() - returns 1 if the stack is empty
 
 
 * Stack variables:
 * size, capacity, top
*/

class Stack{
    public:
    int size;
    int capacity;
    int* array;

    Stack(){
        size = 0; capacity = 100; array = (int*)malloc(capacity * sizeof(int));
        if(array == NULL){
            cout << "Allocation Failed";
            return;
        }
    }
    Stack(int cap){
        size = 0; capacity = cap; array = (int*)malloc(capacity* sizeof(int));
        if(array == NULL){
            cout << "Allocation Failed";
            return;
        }
    }

    void push(int value){
        if(size < capacity){
            array[size] = value;
            size++;
        }else{
            cout << "STACK OVERFLOW" << endl;
        }
    }

    void pop(){
        if(size > 0){
            size--;
        }else{
            cout << "STACK UNDERFLOW" << endl;
        }
    }

    int peek(){
        if(!empty()){
            return array[size - 1];
        }else{
            cout << "STACK EMPTY" << endl;
            return -1;
        }
    }

    void print(){
        if(!empty()){
            for(int i = 0; i < size; i++){
                cout << array[i] << " ";
            }cout << endl;
        }else{
            cout << "Empty stack" << endl;
        }
    }

    bool empty(){
        return size == 0;
    }

    ~Stack(){
        free(array);
    }
};





int main(){
    Stack S;
    S.push(5);
    S.push(8);
    S.push(14);
    S.print();  // 5 8 14

    cout << S.peek() << endl;   // 14

    S.pop();
    S.print();  // 5 8
    S.pop();
    S.print();  // 5

    S.pop();    // fine
    cout << S.empty() << endl;


    S.pop();    // Stack Underflow
    
    Stack S1(2); // Stack of capacity 2
    S1.push(3);  // fine
    S1.push(2);  // fine
    S1.push(8);  // Stack Overflow
}