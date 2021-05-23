// C++ program to find the element
// occurring odd number of times
#include<bits/stdc++.h>
using namespace std;

// Function to find the element
// occurring odd number of times
int getOddOccurrence(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++) {
		
		int count = 0;
		
		for (int j = 0; j < arr_size; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}
		if (count % 2 != 0)
			return arr[i];
	}
	return -1;
}

// driver code
int main()
	{
		int arr[] = { 2, 3, 5, 4, 5, 2,
					4, 3, 5, 2, 4, 4, 2 };
		int n = sizeof(arr) / sizeof(arr[0]);

		// Function calling
		cout << getOddOccurrence(arr, n);

		return 0;
	}
