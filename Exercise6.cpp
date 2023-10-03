#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int k) {
    vector<int> count(k + 1, 0);

    // Count the occurrences of each element
    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i]]++;
    }

    // Calculate cumulative counts
    for (int i = 1; i <= k; ++i) {
        count[i] += count[i - 1];
    }

    vector<int> sorted(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = sorted;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1, 6, 5, 7, 9, 0, 8};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr, 9);  // 9 is the maximum element in the array in this example

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
