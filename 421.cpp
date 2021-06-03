// C++ program to find position of only set bit in a given number
#include <bits/stdc++.h>
using namespace std;

// A utility function to check whether n is a power of 2 or not.
// See http://goo.gl/17Arj
int isPowerOfTwo(unsigned n)
{
	return n && (!(n & (n - 1)));
}

// Returns position of the only set bit in 'n'
int findPosition(unsigned n)
{
	if (!isPowerOfTwo(n))
		return -1;

	unsigned i = 1, pos = 1;

	// Iterate through bits of n till we find a set bit
	// i&n will be non-zero only when 'i' and 'n' have a set bit
	// at same position
	while (!(i & n)) {
		// Unset current bit and set the next bit in 'i'
		i = i << 1;

		// increment position
		++pos;
	}

	return pos;
}

// Driver program to test above function
int main(void)
{
	int n = 16;
	int pos = findPosition(n);
	(pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;

	n = 12;
	pos = findPosition(n);
	(pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;

	n = 128;
	pos = findPosition(n);
	(pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;

	return 0;
}

