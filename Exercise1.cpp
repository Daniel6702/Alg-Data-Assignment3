#include <iostream>
using namespace std;

// Makes a search fuction for the array to see if an given integer is there
bool search(int arr[], int size, int value) {
    // checks if the integer is in the last element
    if (arr[size] == value) {
        return true;
    // if the size reaches zero the value we wnated to search for isnt there
    } else if (size == 0) {
        return false;
    // recursivly calls the function to check the next element
    } else {
        return search(arr, size - 1, value);
    }
}
// connects a pair of integers, one representing min and other max
pair<int,int> find_min_max(int arr[], int size) {
    //if size is 1, min and max initially set to first element
    if (size == 1) {
        return make_pair(arr[0], arr[0]); 
    } else {
        //go backwards through array until size = 1 to start at the front
        pair<int,int> min_max = find_min_max(arr, size - 1); 
        //then go forward through array and compare
        if (arr[size - 1] < min_max.first) {
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