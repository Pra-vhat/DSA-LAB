#include <iostream>
using namespace std;

int main(){
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Enter " << SIZE << " values: ";
    for(int i = 0; i < SIZE; i++){
        cin >> arr[i];
    }

    for(int k = 1; k < SIZE; k++){
        int i = k;
        int j = i - 1;

        if(arr[i] < arr[j]){
            while(j >= 0 && arr[i] < arr[j] ){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i--;
                j--;
            }
        }
    }

    for(int i = 0; i < SIZE; i++){
        cout << arr[i] << " ";
    }

    return 0;

    //1 3 5 8 2 4 6 10 9 7

}