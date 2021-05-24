// C++ Code For A Boolean Matrix Question
#include <bits/stdc++.h>

using namespace std;
#define R 3
#define C 4

void modifyMatrix(bool mat[R][C])
{
	bool row[R];
	bool col[C];

	int i, j;
	
	/* Initialize all values of row[] as 0 */
	for (i = 0; i < R; i++)
	{
	row[i] = 0;
	}

	/* Initialize all values of col[] as 0 */
	for (i = 0; i < C; i++)
	{
	col[i] = 0;
	}

	// Store the rows and columns to be marked as
	// 1 in row[] and col[] arrays respectively
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (mat[i][j] == 1)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	// Modify the input matrix mat[] using the
	// above constructed row[] and col[] arrays
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if ( row[i] == 1 || col[j] == 1 )
			{
				mat[i][j] = 1;
			}
		}
	}
}

/* A utility function to print a 2D matrix */
void printMatrix(bool mat[R][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
}

// Driver Code
int main()
{
	bool mat[R][C] = { {1, 0, 0, 1},
					{0, 0, 1, 0},
					{0, 0, 0, 0}};

	cout << "Input Matrix \n";
	printMatrix(mat);

	modifyMatrix(mat);

	printf("Matrix after modification \n");
	printMatrix(mat);

	return 0;
}


