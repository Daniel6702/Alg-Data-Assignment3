#include <iostream>
using namespace std;

bool search(int arr[], int size, int value) {
    if (arr[size] == value) {
        return true;
    } else if (size == 0) {
        return false;
    } else {
        return search(arr, size - 1, value);
    }
}

pair<int,int> find_min_max(int arr[], int size) {
    if (size == 1) {
        return make_pair(arr[0], arr[0]); //min and max initially set to first element
    } else {
        pair<int,int> min_max = find_min_max(arr, size - 1); //go backwards through array until size = 1 to start at the front
        if (arr[size - 1] < min_max.first) {                 //then go forward through array and compare
            min_max.first = arr[size - 1];
        }
        if (arr[size - 1] > min_max.second) {
            min_max.second = arr[size - 1];
        }
        return min_max;
    }
}


int main(void) {
    int arr[] = {1, 2, 3};
    cout << search(arr, 3, -1) << endl;
    cout << search(arr, 3, 0) << endl;
    cout << search(arr, 3, 1) << endl;
    cout << search(arr, 3, 2) << endl;
    cout << search(arr, 3, 3) << endl;
    cout << search(arr, 3, 4) << endl;
    cout << "Min: " << find_min_max(arr, 3).first << "  Max: " << find_min_max(arr, 3).second << endl;
}