#include <iostream>
using namespace std;

void merge(int* arr, int startIndex, int mid, int endIndex, int* out);
void mergeSort(int* arr, int startIndex, int endIndex, int* out);

int main(){
    // merge sort algorithm


    /*
    1, 3, 5, 7, 9, 2, 4, 5, 8, 10

    1 3 5 7 9               2 4 5 8 10

    1 3 5     7 9          2 4 5    8 10

    1   3    5 7   9      2 4  5    8  10

    1   3    5   7   9 ...



    */

    int maxSize = 10;
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 5, 8, 10};
    int out[10];

    mergeSort(arr, 0, 9, out);

    for(int value: arr){
        cout << value << " ";
    }cout << endl;

    return 0;


}

void merge(int*arr, int startIndex, int M, int endIndex, int* out){

    int left = startIndex;
    int right = M + 1;
    int output = startIndex;

    while(left <= M && right <= endIndex){
        
        if(arr[left] <= arr[right]){
            out[output] = arr[left];
            left++;
        }else{
            out[output] = arr[right];
            right++;
        }

        output++;
    }


    // remaining elements from left half
    while(left <= M){
        out[output] = arr[left];
        left++;
        output++;
    }

    while(right <= endIndex){
        out[output] = arr[right];
        right++;
        output++;
    }

}

void mergeSort(int* arr, int startIndex, int endIndex, int*out){

    if(endIndex > startIndex){

        int M = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, M, out);
        mergeSort(arr, M + 1, endIndex, out);


        // copy merged result back into original array
        merge(arr, startIndex, M, endIndex, out);

        for(int i = startIndex; i <= endIndex; i++){
            arr[i] = out[i];
        }

    }

}