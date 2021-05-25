// C++ program to find a sorted
// sub-sequence of size 3
#include <bits/stdc++.h>
using namespace std;

// A function to fund a sorted
// sub-sequence of size 3
void find3Numbers(int arr[], int n)
{
	// Index of maximum element
	// from right side
	int max = n - 1;

	// Index of minimum element
	// from left side
	int min = 0;
	int i;

	// Create an array that will store
	// index of a smaller element on left side.
	// If there is no smaller element on left
	// side, then smaller[i] will be -1.
	int* smaller = new int[n];

	// first entry will always be -1
	smaller[0] = -1;
	for (i = 1; i < n; i++) {
		if (arr[i] <= arr[min]) {
			min = i;
			smaller[i] = -1;
		}
		else
			smaller[i] = min;
	}

	// Create another array that will
	// store index of a greater element
	// on right side. If there is no greater
	// element on right side, then
	// greater[i] will be -1.
	int* greater = new int[n];

	// last entry will always be -1
	greater[n - 1] = -1;
	for (i = n - 2; i >= 0; i--) {
		if (arr[i] >= arr[max]) {
			max = i;
			greater[i] = -1;
		}
		else
			greater[i] = max;
	}

	// Now find a number which has both
	// a greater number on right side and
	// smaller number on left side
	for (i = 0; i < n; i++) {
		if (smaller[i] != -1 && greater[i] != -1) {
			cout << arr[smaller[i]]
				<< " " << arr[i] << " "
				<< arr[greater[i]];
			return;
		}
	}

	// If we reach number, then there are
	// no such 3 numbers
	cout << "No such triplet found";

	// Free the dynamically allocated memory
	// to avoid memory leak
	delete[] smaller;
	delete[] greater;

	return;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 10, 5, 6, 2, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	find3Numbers(arr, n);
	return 0;
	a greater number on
}


