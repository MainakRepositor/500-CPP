// C++ program to Find the two repeating
// elements in a given array
#include<bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int size)
{
	int i, j;
	printf(" Repeating elements are ");
	for(i = 0; i < size; i++)
		for(j = i + 1; j < size; j++)
		if(arr[i] == arr[j])
			cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = {4, 2, 4, 5, 2, 3, 1};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printRepeating(arr, arr_size);
}


