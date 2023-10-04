#ifndef _SORT_H_
#define _SORT_H_
#include <vector>
/**
 *
 * Several sorting routines.
 * Arrays are rearranged with smallest item first.
 */

//
// SELECTION SORT IMPLEMENTATION EXERCISE 5!!!
// 

template <typename T>
void selection_sort(vector<T>& A) {
    int n = A.size();
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        swap(A[i], A[min_index]);
    }
}

using namespace std;


#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

#endif
