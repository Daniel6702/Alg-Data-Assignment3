//
// Time complexity for ex5:
//
/* Best Case: The best-case running time for selection sort is always the same as the worst-case 
and average-case time complexities, which is O(n^2).
This is because selection sort always performs the same number of comparisons
and swaps regardless of the initial order of elements.

Worst Case: The worst-case time complexity of selection sort is O(n^2),
where n is the number of elements to be sorted. It performs approximately n(n-1)/2 
comparisons and n-1 swaps in the worst case. 
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort
template <typename AnyType>
void selectionSort(vector<AnyType>& a) {
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