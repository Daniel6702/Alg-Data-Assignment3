#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include <vector>

template <typename T>
void selection_sort(std::vector<T>& A) {
    int n = A.size();
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        std::swap(A[i], A[min_index]);
    }
}

#endif
