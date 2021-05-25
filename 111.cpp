// C++ program to find minimum
// element in a sorted and rotated array
#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
	// This condition is needed to
	// handle the case when array is not
	// rotated at all
	if (high < low) return arr[0];

	// If there is only one element left
	if (high == low) return arr[low];

	// Find mid
	int mid = low + (high - low)/2; /*(low + high)/2;*/

	// Check if element (mid+1) is minimum element. Consider
	// the cases like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid + 1] < arr[mid])
	return arr[mid + 1];

	// Check if mid itself is minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
	return arr[mid];

	// Decide whether we need to go to left half or right half
	if (arr[high] > arr[mid])
	return findMin(arr, low, mid - 1);
	return findMin(arr, mid + 1, high);
}

// Driver program to test above functions
int main()
{
	int arr1[] = {5, 6, 1, 2, 3, 4};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << "The minimum element is " << findMin(arr1, 0, n1-1) << endl;

	int arr2[] = {1, 2, 3, 4};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	cout << "The minimum element is " << findMin(arr2, 0, n2-1) << endl;

	int arr3[] = {1};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	cout<<"The minimum element is "<<findMin(arr3, 0, n3-1)<<endl;

	int arr4[] = {1, 2};
	int n4 = sizeof(arr4)/sizeof(arr4[0]);
	cout<<"The minimum element is "<<findMin(arr4, 0, n4-1)<<endl;

	int arr5[] = {2, 1};
	int n5 = sizeof(arr5)/sizeof(arr5[0]);
	cout<<"The minimum element is "<<findMin(arr5, 0, n5-1)<<endl;

	int arr6[] = {5, 6, 7, 1, 2, 3, 4};
	int n6 = sizeof(arr6)/sizeof(arr6[0]);
	cout<<"The minimum element is "<<findMin(arr6, 0, n6-1)<<endl;

	int arr7[] = {1, 2, 3, 4, 5, 6, 7};
	int n7 = sizeof(arr7)/sizeof(arr7[0]);
	cout << "The minimum element is " << findMin(arr7, 0, n7-1) << endl;

	int arr8[] = {2, 3, 4, 5, 6, 7, 8, 1};
	int n8 = sizeof(arr8)/sizeof(arr8[0]);
	cout << "The minimum element is " << findMin(arr8, 0, n8-1) << endl;

	int arr9[] = {3, 4, 5, 1, 2};
	int n9 = sizeof(arr9)/sizeof(arr9[0]);
	cout << "The minimum element is " << findMin(arr9, 0, n9-1) << endl;

	return 0;
}


