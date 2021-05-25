// C++ Program to check if two
// given matrices are identical
#include <bits/stdc++.h>
#define N 4
using namespace std;

// This function returns 1 if A[][] and B[][] are identical
// otherwise returns 0
int areSame(int A[][N], int B[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (A[i][j] != B[i][j])
				return 0;
	return 1;
}

int main()
{
	int A[N][N] = { {1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3},
					{4, 4, 4, 4}};

	int B[N][N] = { {1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3},
					{4, 4, 4, 4}};

	if (areSame(A, B))
		cout << "Matrices are identical";
	else
		cout << "Matrices are not identical";
	return 0;
}

