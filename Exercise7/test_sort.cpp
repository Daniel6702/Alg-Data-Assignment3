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

/*
Test the modified quicksort algorithm with introsort. With different input sizes. Each size is tested 10 times. The average time is calculated and printed.
*/
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

/* DATA
Different input sizes can give us insights into how the algorithm scales
Altering threshold for when to swich from a quicksort to a simpler algorithm, like insertion sort, can influence performance. 
Too early, and you may do unecesary simple sorts. Too late, and you may perform more complex sorting than necessary.

useInsertion = 8
Size: 100, Average Time: 0 s
Size: 1000, Average Time: 0.00079996 s
Size: 2000, Average Time: 0.00420006 s
Size: 4000, Average Time: 0.0162609 
Size: 8000, Average Time: 0.0738606 s
Size: 100000, Average Time: 10.4516 s

useInsertion = 16
Size: 100, Average Time: 0 s
Size: 1000, Average Time: 0.00180005 s
Size: 2000, Average Time: 0.00539992 s
Size: 4000, Average Time: 0.0139603 s
Size: 8000, Average Time: 0.0716565 s
Size: 100000, Average Time: 8.77487 s

useInsertion = 32
Size: 100, Average Time: 0s
Size: 1000, Average Time: 0.00110001 s
Size: 2000, Average Time: 0.00409995 s
Size: 4000, Average Time: 0.0163 s
Size: 8000, Average Time: 0.0743982 s
Size: 100000, Average Time: 9.9473 s

useInsertion = 64
Size: 100, Average Time: 0 s
Size: 1000, Average Time: 0.00109999 s
Size: 2000, Average Time: 0.0044 s
Size: 4000, Average Time: 0.0145 s
Size: 8000, Average Time: 0.0620615 s
Size: 100000, Average Time: 11.1432 s

useInsertion = 96
Size: 100, Average Time: 0 s
Size: 1000, Average Time: 0.00109998 s
Size: 2000, Average Time: 0.0035 s
Size: 4000, Average Time: 0.0141014 s
Size: 8000, Average Time: 0.0551604 s
Size: 100000, Average Time: 9.74908 s

Using built-in sort
Size: 100, Average Time: 0 s
Size: 1000, Average Time: 0.00010001 s
Size: 2000, Average Time: 0.00010009 s
Size: 4000, Average Time: 0.00040006 s
Size: 8000, Average Time: 0.00090005 s
Size: 100000, Average Time: 0.0144018 s

How do they compare?
The built-in sort is much faster.

*/