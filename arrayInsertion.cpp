// done at school

#include <iostream>
#include <vector>
using namespace std;

class Array{
      public:
      int size = 0;
      int capacity = 100;
      int arr[100];// by default the size will be 100
      
      bool isFull(){
           if(size == capacity){
                   return 1;
           }
           }
      
      // insert at an index
      // shift right
      void insert(int value, int index){
           if(size < capacity){
                   for(int i = capacity - 1; i >= index; i--){
                           arr[i] = arr[i - 1];
                           }
                   arr[index] = value;
                   size ++;
                   }
      }
      
      // delete at a given index
      // left shift
      void dele(int index){
           for(int i = index; i < capacity; i++){
                   arr[i] = arr[i + 1];
                   }
           size --;
           }
           
      void printArray(){
           for(int i = 0; i < size; i++){
                   cout << arr[i] << " ";
                   }
           cout << endl;
           }
};
           

// array insertion and deletion

int main(){
    Array arr;
    arr.insert(5,0);
    arr.insert(6,1);
    arr.insert(7,2);
    arr.insert(9,3);
    arr.printArray();
    
    arr.dele(2); // delete the element at index 2;
    arr.printArray();
    
    
}