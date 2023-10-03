#include <iostream>
using namespace std;

/*
The function prints out m '*', then recursivly m+1. When the recursion ends (triangle peak) m>n. 
We just again print m '*' thus mirroring the pattern in reverse during the recursion unwind.
*/
void triangle(int m, int n) {
    if (m > n) {
        return;
    }
    for (int i = 0; i < m; i++) {
        cout << "*";
    }
    cout << endl;
    triangle(m + 1, n);
    for (int i = 0; i < m; i++) {
        cout << "*";
    }
    cout << endl;
}

int main(void) {
    triangle(4,6);
    return 0;
}











/*
void triangle1(int m, int n) {
    if (m <= n) {
        for (int i = 0; i < m; i++) {
            cout << "*";
        }
        cout << endl;
        triangle1(m+1,n);
    } else if (m >= n && m > 0) {
        for (int i = 1; i < m; i++) {
            cout << "*";
        }
        cout << endl;
        triangle1(m-1,n-1);
    } else {
        return;
    }
}
*/