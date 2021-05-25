// CPP program to find the row
// with maximum number of 1s
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

// Function to find the index of first index
// of 1 in a boolean array arr[]
int first(bool arr[], int low, int high)
{
	if(high >= low)
	{
		// Get the middle index
		int mid = low + (high - low)/2;
	
		// Check if the element at middle index is first 1
		if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
			return mid;
	
		// If the element is 0, recur for right side
		else if (arr[mid] == 0)
			return first(arr, (mid + 1), high);
		
		// If element is not first 1, recur for left side
		else
			return first(arr, low, (mid -1));
	}
	return -1;
}

// Function that returns index of row
// with maximum number of 1s.
int rowWithMax1s(bool mat[R][C])
{
	// Initialize max values
	int max_row_index = 0, max = -1;

	// Traverse for each row and count number of 1s
	// by finding the index of first 1
	int i, index;
	for (i = 0; i < R; i++)
	{
		index = first (mat[i], 0, C-1);
		if (index != -1 && C-index > max)
		{
			max = C - index;
			max_row_index = i;
		}
	}

	return max_row_index;
}

// Driver Code
int main()
{
	bool mat[R][C] = { {0, 0, 0, 1},
					{0, 1, 1, 1},
					{1, 1, 1, 1},
					{0, 0, 0, 0}};

	cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);

	return 0;
}


