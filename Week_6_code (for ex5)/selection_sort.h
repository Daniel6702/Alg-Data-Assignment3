#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include <vector>

template <typename T>
void selection_sort(std::vector<T>& A) {
    int n = A.size();
     // The outer loop iterates through each element of the vector except the last one
    for (int i = 0; i < n-1; i++) {
        // Assume the current index is the minimum
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            // Compare the current element with the element at 'min_index'
            // If the current element is smaller, update 'min_index'
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        // After finding the minimum element in the unsorted part of the array,
        // swap it with the first element of the unsorted part
        std::swap(A[i], A[min_index]);
    }
}

#endif
