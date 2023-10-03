#include <iostream>
#include <vector>
//#include "sort.h"
#include <time.h>

using namespace std;

void checkSort(const vector<int>& a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] >= a[i + 1]) {
			cout << "Error at " << i << endl;
		}
	}
	cout << "Finished checksort" << endl;
}


template <typename AnyType>
void permute(vector<AnyType>& a) {
	for (int j = 1; j < a.size(); ++j) {
		swap(a[j], a[rand() % j]);
	}
}

//
// SELECTION SORT IMPLEMENTATION EXERCISE 5!!!
// 
template <typename AnyType>
void selectionSort(vector<AnyType>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
    }
}


int main() {
	const int NUM_ITEMS = 1000;

	vector<int>a(NUM_ITEMS);
	for (int i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] + 'a';
	}

	for (int theSeed = 0; theSeed < 10; ++theSeed) {
		srand(time(0) + theSeed);

		// Test of selectionSort
		permute(a);
		selectionSort(a);
		checkSort(a);

		
		permute(a);
		insertionSort(a);
		checkSort(a);

		permute(a);
		insertionSort(begin(a), end(a));
		checkSort(a);

		permute(a);
		mergeSort(a);
		checkSort(a);

		permute(a);
		quickSort(a);
		checkSort(a); 
	}

	return 0;
}