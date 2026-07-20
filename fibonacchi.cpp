// bad version-- has case specific handling

#include <iostream>
using namespace std;

void fibonacchi(int, long long int = 0, long long int = 1, bool = 1);

int main(){

    int n = 22;


    for(int i = 0; i < n; i++){
        cout << "n = " << i << ": ";
        fibonacchi(i);
        cout << endl << endl;
    }

}

void fibonacchi(int n, long long int prev2, long long int prev1, bool first){
    
    if(first){
        cout << prev2 << " " << prev1 << " ";
        if(n < 3) return;
    }
    long long int current;

    current = prev2 + prev1;
    cout << current << " ";

    if(n == 3){
        return;
    }

    fibonacchi(n-1, prev1, current, 0);
}