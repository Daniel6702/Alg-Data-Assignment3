#include <iostream>
#include <vector>
#include <time.h>
#include "sort.h"
#include "quick_sort.h"
#include <chrono>
#include<algorithm>

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


// Test the modified quicksort algorithm with introsort. With different input sizes. Each size is tested 10 times. The average time is calculated and printed.
int main() {
    vector<int> inputSizes = {100, 1000, 2000, 4000, 8000, 100000}; // Sizes you want to test
    
    for(int NUM_ITEMS : inputSizes) {
        vector<int> a(NUM_ITEMS);
        vector<double> elapsedTimes; 
        
        // Initialize a
        for (int i = 1; i < a.size(); ++i) {
            a[i] = a[i - 1] + 'a';
        }

        for (int theSeed = 0; theSeed < 10; ++theSeed) {
            srand(time(0) + theSeed);
            vector<int> b = a; // Create a copy of `a` to keep the original unpermuted vector intact
            permute(b);

            // Measure time taken for sorting
            auto start = chrono::high_resolution_clock::now();
            quickSort(b);
			//sort(b.begin(), b.end());
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;

            // Check if sorting is correct
            checkSort(b);

            // Push the elapsed time into the vector
            elapsedTimes.push_back(elapsed.count());
        }

        // Calculate average time
        double sum = 0.0;
        for(double time : elapsedTimes) {
            sum += time;
        }
        double averageTime = sum / elapsedTimes.size();
        
        cout << "Size: " << NUM_ITEMS << ", Average Time: " << averageTime << " s\n";
    }

    return 0;
}