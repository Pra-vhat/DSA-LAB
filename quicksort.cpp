// three programs: selection, merge, quick


// this one is quick sort
#include <iostream>
using namespace std;

int partition(int*, int, int, int);
void quicksort(int*, int, int);

int main(){
    int MAX_SIZE;

    MAX_SIZE = 10;
    // cin >> MAX_SIZE; // comment/uncomment

    int arr[MAX_SIZE] = {1, 3, 5, 7, 9, 2, 4, 5, 8, 10};

    // comment/uncomment
    // for(int i = 0; i < MAX_SIZE; i++){
    //     cin >> arr[i];
    // }

    // the first part is pivot selection
    // the second part is compartmentalization? oh it's partitioning

    // if 4 is selected as the pivot, the partition is as follows:
    // 1 3 2 _4_ 5 7 9 5 8 10

    /*
    Solve by selecting only the first element as the pivot

    1 3 5 7 9 2 4 5 8 10

    () 1 (3 5 7 9 2 4 5 8 10)
    1 (2) 3 (5 7 9 4 5 8 10)
    1 2 3 (4) 5 (7 9 5 8 10)
    1 2 3 4 5 (5) 7 (9 8 10)
    1 2 3 4 5 5 7 (8) 9 (10)
    1 2 3 4 5 5 7 8 9 10

    */

    quicksort(arr, 0, MAX_SIZE - 1);

    for(int value: arr){
        cout << value << " ";
    }cout << endl;



}

int partition(int* arr, int pivotIndex, int firstIndex, int lastIndex){
    int greater, smaller;

    greater = firstIndex;
    smaller = lastIndex;

    while(greater < smaller){
        while(greater <= lastIndex &&
            arr[greater] < arr[pivotIndex]){    // skip the elements that are smaller than the pivot
            greater++;
        }
        while(smaller >= firstIndex &&
            arr[smaller] > arr[pivotIndex]){    //  skip the elements that are greater than the pivot
            smaller--;
        }

        if(greater < smaller){
            swap(arr[greater], arr[smaller]);
            greater++;
        }else{
            swap(arr[smaller], arr[pivotIndex]);
            return smaller;
        }
    }

}

void quicksort(int* arr, int firstIndex, int lastIndex){
    int start, end;
    
    start = firstIndex;
    end = lastIndex;

    if(firstIndex < lastIndex){
        int pivotIndex = partition(arr, start, start + 1, end);
        if(pivotIndex > firstIndex) quicksort(arr, start, pivotIndex - 1);
        if(pivotIndex < lastIndex - 1) quicksort(arr, pivotIndex + 1, end);
    }else{
        return;
    }
}