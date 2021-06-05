// C++ program to find out
// maximum value from a given
// sequence of coins
#include <bits/stdc++.h>
using namespace std;

// Returns optimal value possible
// that a player can collect from
// an array of coins of size n.
// Note than n must be even
int optimalStrategyOfGame(
	int* arr, int n)
{
	// Create a table to store
	// solutions of subproblems
	int table[n][n];

	// Fill table using above
	// recursive formula. Note
	// that the table is filled
	// in diagonal fashion (similar
	// to http:// goo.gl/PQqoS),
	// from diagonal elements to
	// table[0][n-1] which is the result.
	for (int gap = 0; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			// Here x is value of F(i+2, j),
			// y is F(i+1, j-1) and
			// z is F(i, j-2) in above recursive
			// formula
			int x = ((i + 2) <= j)
						? table[i + 2][j]
						: 0;
			int y = ((i + 1) <= (j - 1))
						? table[i + 1][j - 1]
						: 0;
			int z = (i <= (j - 2))
						? table[i][j - 2]
						: 0;

			table[i][j] = max(
				arr[i] + min(x, y),
				arr[j] + min(y, z));
		}
	}

	return table[0][n - 1];
}

// Driver program to test above function
int main()
{
	int arr1[] = { 8, 15, 3, 7 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	printf("%d\n",
		optimalStrategyOfGame(arr1, n));

	int arr2[] = { 2, 2, 2, 2 };
	n = sizeof(arr2) / sizeof(arr2[0]);
	printf("%d\n",
		optimalStrategyOfGame(arr2, n));

	int arr3[] = { 20, 30, 2, 2, 2, 10 };
	n = sizeof(arr3) / sizeof(arr3[0]);
	printf("%d\n",
		optimalStrategyOfGame(arr3, n));

	return 0;
}
