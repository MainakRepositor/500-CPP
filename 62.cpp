// C++ program to find maximum
// element
#include <bits/stdc++.h>
using namespace std;

// function to find the maximum element
int findMaximum(int arr[], int low, int high)
{
	int max = arr[low];
	int i;
	for (i = low + 1; i <= high; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		
		// break when once an element is smaller than
		// the max then it will go on decreasing
		// and no need to check after that
		else
			break;
	}
	return max;
}

/* Driver code*/
int main()
{
	int arr[] = {1, 30, 40, 50, 60, 70, 23, 20};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The maximum element is " << findMaximum(arr, 0, n-1);
	return 0;
}


