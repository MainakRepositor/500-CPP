// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

/* Function to get index of ceiling of x in arr[low..high] */
int ceilSearch(int arr[], int low, int high, int x)
{
	
	int i;
	
	/* If x is smaller than or equal to first element,
		then return the first element */
	if(x <= arr[low])
		return low;
	
	/* Otherwise, linearly search for ceil value */
	for(i = low; i < high; i++)
	{
		if(arr[i] == x)
		return i;
	
		/* if x lies between arr[i] and arr[i+1] including
		arr[i+1], then return arr[i+1] */
		if(arr[i] < x && arr[i+1] >= x)
		return i+1;
	}	
	
	/* If we reach here then x is greater than the last element
		of the array, return -1 in this case */
	return -1;
}


/* Driver code*/
int main()
{
	int arr[] = {1, 2, 8, 10, 10, 12, 19};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 3;
	int index = ceilSearch(arr, 0, n-1, x);
	if(index == -1)
		cout << "Ceiling of " << x << " doesn't exist in array ";
	else
		cout << "ceiling of " << x << " is " << arr[index];
	
	return 0;
}


