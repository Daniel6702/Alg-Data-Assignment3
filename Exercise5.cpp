#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void selectionSort(vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        // Assume the current index is the minimum
        int minIdx = i;
        // Find the smallest element's index in the remaining unsorted part
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(a[i], a[minIdx]);
    }
}

int main() {
    vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original Array: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
    selectionSort(a);
    cout << "Sorted Array: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}