#include <iostream>
using namespace std;

int fibonacci(int, int = 0, int = 1);
void printfibonacci(int, int = 0, int = 1);

int main(){
    cout << fibonacci(8) << endl;
    printfibonacci(8);
    return 0;
}

int fibonacci(int n, int a, int b){
    if(n == 1) return a;
    a += b;
    fibonacci(n - 1, b, a);
}

void printfibonacci(int n, int a, int b){
    cout << a << " ";
    a += b;
    if(n == 1) return;
    printfibonacci(n - 1, b, a);
}