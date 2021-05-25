// C++ Program to replace every element with the greatest
// element on right side
#include <bits/stdc++.h>
using namespace std;

/* Function to replace every element with the
next greatest element */
void nextGreatest(int arr[], int size)
{
	
	// Initialize the next greatest element
	int max_from_right = arr[size-1];
	
	// The next greatest element for the rightmost element
	// is always -1
	arr[size-1] = -1;
	
	// Replace all other elements with the next greatest
	for(int i = size-2; i >= 0; i--)
	{
		// Store the current element (needed later for updating
		// the next greatest element)
		int temp = arr[i];
	
		// Replace current element with the next greatest
		arr[i] = max_from_right;
	
		// Update the greatest element, if needed
		if(max_from_right < temp)
		max_from_right = temp;
	}
}

/* A utility Function that prints an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/* Driver program to test above function */
int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	nextGreatest (arr, size);
	cout << "The modified array is: \n";
	printArray (arr, size);
	return (0);
}

