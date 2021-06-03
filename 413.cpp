// C++ Program to swap bits
// in a given number
#include <bits/stdc++.h>
using namespace std;

int swapBits(unsigned int x, unsigned int p1,
			unsigned int p2, unsigned int n)
{
	/* Move all bits of first set to rightmost side */
	unsigned int set1 = (x >> p1) & ((1U << n) - 1);

	/* Move all bits of second set to rightmost side */
	unsigned int set2 = (x >> p2) & ((1U << n) - 1);

	/* Xor the two sets */
	unsigned int Xor = (set1 ^ set2);

	/* Put the Xor bits back to their original positions */
	Xor = (Xor << p1) | (Xor << p2);

	/* Xor the 'Xor' with the original number so that the
	two sets are swapped */
	unsigned int result = x ^ Xor;

	return result;
}

/* Driver code*/
int main()
{
	int res = swapBits(28, 0, 3, 2);
	cout << "Result = " << res;
	return 0;
}

