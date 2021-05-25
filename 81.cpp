// C++ program for naive solution to
// print all combination of 4 elements
// in A[] with sum equal to X
#include <bits/stdc++.h>
using namespace std;

/* A naive solution to print all combination
of 4 elements in A[]with sum equal to X */
void findFourElements(int A[], int n, int X)
{
	
// Fix the first element and find other three
for (int i = 0; i < n - 3; i++)
{
	// Fix the second element and find other two
	for (int j = i + 1; j < n - 2; j++)
	{
		
		// Fix the third element and find the fourth
		for (int k = j + 1; k < n - 1; k++)
		{
			// find the fourth
			for (int l = k + 1; l < n; l++)
			if (A[i] + A[j] + A[k] + A[l] == X)
				cout << A[i] <<", " << A[j]
					<< ", " << A[k] << ", " << A[l];
		}
	}
}
}

// Driver Code
int main()
{
	int A[] = {10, 20, 30, 40, 1, 2};
	int n = sizeof(A) / sizeof(A[0]);
	int X = 91;
	findFourElements (A, n, X);
	return 0;
}

