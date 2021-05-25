// Program for in-place matrix transpose
#include <stdio.h>
#include <iostream>
#include <bitset>
#define HASH_SIZE 128

using namespace std;

// A utility function to print a 2D array of size nr x nc and base address A
void Print2DArray(int *A, int nr, int nc)
{
	for(int r = 0; r < nr; r++)
	{
		for(int c = 0; c < nc; c++)
			printf("%4d", *(A + r*nc + c));

		printf("\n");
	}

	printf("\n\n");
}

// Non-square matrix transpose of matrix of size r x c and base address A
void MatrixInplaceTranspose(int *A, int r, int c)
{
	int size = r*c - 1;
	int t; // holds element to be replaced, eventually becomes next element to move
	int next; // location of 't' to be moved
	int cycleBegin; // holds start of cycle
	int i; // iterator
	bitset<HASH_SIZE> b; // hash to mark moved elements

	b.reset();
	b[0] = b[size] = 1;
	i = 1; // Note that A[0] and A[size-1] won't move
	while (i < size)
	{
		cycleBegin = i;
		t = A[i];
		do
		{
			// Input matrix [r x c]
			// Output matrix
			// i_new = (i*r)%(N-1)
			next = (i*r)%size;
			swap(A[next], t);
			b[i] = 1;
			i = next;
		}
		while (i != cycleBegin);

		// Get Next Move (what about querying random location?)
		for (i = 1; i < size && b[i]; i++)
			;
		cout << endl;
	}
}

// Driver program to test above function
int main(void)
{
	int r = 5, c = 6;
	int size = r*c;
	int *A = new int[size];

	for(int i = 0; i < size; i++)
		A[i] = i+1;

	Print2DArray(A, r, c);
	MatrixInplaceTranspose(A, r, c);
	Print2DArray(A, c, r);

	delete[] A;

	return 0;
}
