// C++ program for subtraction of matrices
#include <bits/stdc++.h>
using namespace std;
#define N 4

// This function subtracts B[][] from A[][], and stores
// the result in C[][]
void subtract(int A[][N], int B[][N], int C[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			C[i][j] = A[i][j] - B[i][j];
}

// Driver code
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

	int C[N][N]; // To store result
	int i, j;
	subtract(A, B, C);

	cout << "Result matrix is " << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		cout << C[i][j] << " ";
		cout << endl;
	}

	return 0;
}


