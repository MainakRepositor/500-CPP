// C++ code to count the number of
// possible triangles using brute
// force approach
#include <bits/stdc++.h>
using namespace std;

// Function to count all possible
// triangles with arr[] elements
int findNumberOfTriangles(int arr[], int n)
{
	// Count of triangles
	int count = 0;

	// The three loops select three
	// different values from array
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			// The innermost loop checks for
			// the triangle property
			for (int k = j + 1; k < n; k++)

				// Sum of two sides is greater
				// than the third
				if (
					arr[i] + arr[j] > arr[k]
					&& arr[i] + arr[k] > arr[j]
					&& arr[k] + arr[j] > arr[i])
					count++;
		}
	}
	return count;
}

// Driver code
int main()
{
	int arr[] = { 10, 21, 22, 100, 101, 200, 300 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout
		<< "Total number of triangles possible is "
		<< findNumberOfTriangles(arr, size);

	return 0;
}
