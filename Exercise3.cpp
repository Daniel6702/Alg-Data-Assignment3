#include <iostream>
using namespace std;

void bookletPrint(int startPage, int endPage) {
    if (startPage > endPage) {
        return;
    }
    //The sheet count is based on 'startPage', which increments by 2 in each recursion. 
    // Thus a sequence like {1,3,5} is mapped to {1,2,3} using f(x)=(x+1)/2
    cout << "Sheet " << (startPage+1)/2 << " contains pages "; 
    cout << startPage << " " << startPage+1 << " " << endPage-1 << " " << endPage << endl;
    //increment and decrement from either end. 4 pages per sheet, thus +2, -2
    bookletPrint(startPage + 2, endPage - 2); 
}

int main(void) {
    bookletPrint(1,12);
    return 0;
}