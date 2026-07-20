#include <iostream>
using namespace std;

void towerofhanoi(int, char = 'A', char = 'B', char = 'C');

int main(){
    cout << "n = 1" << endl;
    towerofhanoi(1);
    cout <<"n = 2" << endl;
    towerofhanoi(2);
    cout << "n = 3" << endl;
    towerofhanoi(3);
    cout << "n = 4" << endl;
    towerofhanoi(4);
}

void towerofhanoi(int n, char start, char auxiliary, char destination){
    if(n == 1){
        // move directly to destination
        // i.e. from start to destination, using auxiliary peg as support
        cout << "Move disc from peg " << start << " to " << destination << endl;
        return;
    }
    // or move n - 1 discs to auxiliary
    towerofhanoi(n - 1, start, destination, auxiliary);
    cout << "Move disc from peg " << start << " to " << destination << endl;
    // move back then - 1 discs back from auxiliary to destination
    towerofhanoi(n - 1, auxiliary, start, destination);
}