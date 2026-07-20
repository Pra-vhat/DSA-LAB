#include <stdio.h>
#include <stdlib.h>

void printarray(int** arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d  ", **(arr + i));
    }
    printf("\n");
}

void main(){
    int capacity = 5, size = 0;
    int* arr = (int*) (malloc(capacity * sizeof(int)));

    for(int i = 0; i < capacity; i++){
        arr[i] = i + 1;
        size++;
    }

    printarray(&arr, size);

    // for(int i = 0; i < size; i++){
    //     printf("%d  ", arr[i]);
    // }
    // printf("\n");
}