// three programs: selection, merge, quick


// this one is selection sort
#include <iostream>
using namespace std;

#define MAX_SIZE 10

int main(){
    int arr[MAX_SIZE] = {1, 3, 5, 7, 9 ,2, 4, 5, 8, 10};

    for(int i = MAX_SIZE - 1; i >= 0; i--){

        int max = arr[i];
        int index = i;

        for(int j = i - 1; j >= 0; j--){
            if(arr[j] > max){
                max = arr[j];
                index = j;
            }
        }

        // swapping arr[index] and arr[i]
        arr[index] = arr[i];
        arr[i] = max;

    }

    for(int value: arr){
        cout << value << " ";
    }cout << endl;

    return 0;
}