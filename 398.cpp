// Count number of bits to be flipped
// to convert A into B
#include <iostream>
using namespace std;

// Function that count set bits
int countSetBits(int n)
{
	int count = 0;
	while (n > 0)
	{
		count++;
		n &= (n-1);
	}
	return count;
}

// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
	// Return count of set bits in
	// a XOR b
	return countSetBits(a^b);
}

// Driver code
int main()
{
	int a = 10;
	int b = 20;
	cout << FlippedCount(a, b)<<endl;
	return 0;
}
