/* A simple program to count pairs with difference k*/
#include<iostream>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0;
	
	// Pick all elements one by one
	for (int i = 0; i < n; i++)
	{	
		// See if there is a pair of this picked element
		for (int j = i+1; j < n; j++)
			if (arr[i] - arr[j] == k || arr[j] - arr[i] == k )
				count++;
	}
	return count;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 5, 3, 4, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << "Count of pairs with given diff is "
		<< countPairsWithDiffK(arr, n, k);
	return 0;
}
