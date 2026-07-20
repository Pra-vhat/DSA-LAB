#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int index = n - 1;
        while((arr[index] <= 0) && (index >=0)){
            index--;
        }

        pair <int, int> value_index;
        int minimum = arr[index];
        while((arr[index] >= 0 && index != 0)){
            if(arr[index] == 0){
                index--;
                continue;
            }
            if(arr[index] < minimum){
                minimum = arr[index];
                value_index.first = minimum;
                value_index.second = index;
            }
            index--;
        }

        if(abs(arr[index]) > value_index.first)


    }
}