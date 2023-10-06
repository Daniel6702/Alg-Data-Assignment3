#include <iostream>
using namespace std;

void triangle(int m, int n) {
    //once m reaches n, the recursive function will begin to unwind
    if (m > n) {
        return;
    }
    // prints out m number of '*'
    for (int i = 0; i < m; i++) {
        cout << "*";
    }
    cout << endl;
     // recursively calls the function with m+1
    triangle(m + 1, n);
     // Print m '*' characters on a line again. mirroring in reverse during recursion unwind
    for (int i = 0; i < m; i++) {
        cout << "*";
    }
    cout << endl;
}

int main(void) {
    triangle(2,7);
    return 0;
}