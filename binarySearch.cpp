#include <iostream>
using namespace std;

int main(){
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Enter " << SIZE << " values: ";
    for(int i = 0; i < SIZE; i++){
        cin >> arr[i];
    }

    int query;
    cout << "Enter the search query: ";
    cin >> query;

    // for(int i = 0; i < SIZE; i++){
    //     for(int j = i + 1; j < SIZE; j++){
    //         if(arr[i] > arr[j]){
    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }

    cout << "Sorted array: ";
    for(int i = 0; i < SIZE; i++){
        cout << arr[i] << " ";
    }

    int L = 0, R = SIZE - 1, M = -1;
    bool found = false;

    while(L <= R){
        M = (L + R) / 2;
        if(arr[M] == query){
            cout << "Query found at position " << M + 1 << endl;
            found = true;
            break;
        }else if(query < arr[M]){
            R = M - 1;
        }else{
            L = M + 1;
        }
    }

    if(!found){
        cout << "Query not found." << endl;
    }
}