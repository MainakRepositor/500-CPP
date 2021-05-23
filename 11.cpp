// C++ program to Merge an array of
// size n into another array of size m + n
#include <bits/stdc++.h>
using namespace std;

/* Assuming -1 is filled for the places
where element is not available */
#define NA -1

/* Function to move m elements at
the end of array mPlusN[] */
void moveToEnd(int mPlusN[], int size)
{
int j = size - 1;
for (int i = size - 1; i >= 0; i--)
	if (mPlusN[i] != NA)
	{
		mPlusN[j] = mPlusN[i];
		j--;
	}
}

/* Merges array N[] of size n into
array mPlusN[] of size m+n*/
int merge(int mPlusN[], int N[], int m, int n)
{
int i = n; /* Current index of i/p part of mPlusN[]*/
int j = 0; /* Current index of N[]*/
int k = 0; /* Current index of output mPlusN[]*/
while (k < (m + n))
{
	/* Take an element from mPlusN[] if
	a) value of the picked element is smaller
	and we have not reached end of it
	b) We have reached end of N[] */
	if ((j == n)||(i < (m + n) && mPlusN[i] <= N[j]))
	{
		mPlusN[k] = mPlusN[i];
		k++;
		i++;
	}
	else // Otherwise take element from N[]
	{
	mPlusN[k] = N[j];
	k++;
	j++;
	}
}
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

/* Driver code */
int main()
{
/* Initialize arrays */
int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
int N[] = {5, 7, 9, 25};
	
int n = sizeof(N) / sizeof(N[0]);
int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;

/*Move the m elements at the end of mPlusN*/
moveToEnd(mPlusN, m + n);

/*Merge N[] into mPlusN[] */
merge(mPlusN, N, m, n);

/* Print the resultant mPlusN */
printArray(mPlusN, m+n);

return 0;
}
