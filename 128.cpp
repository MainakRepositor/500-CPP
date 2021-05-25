#include <stdio.h>
#define M 3
#define N 4

// This function stores transpose of A[][] in B[][]
void transpose(int A[][N], int B[][M])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			B[i][j] = A[j][i];
}

int main()
{
	int A[M][N] = { {1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3}};

	// Note dimensions of B[][]
	int B[N][M], i, j;

	transpose(A, B);

	printf("Result matrix is \n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		printf("%d ", B[i][j]);
		printf("\n");
	}

	return 0;
}
