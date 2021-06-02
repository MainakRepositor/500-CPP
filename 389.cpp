// C++ program to find
// smallest power of 2
// greater than or equal to n
#include <bits/stdc++.h>
using namespace std;

unsigned int nextPowerOf2(unsigned int n)
{
	unsigned count = 0;
	
	// First n in the below condition
	// is for the case where n is 0
	if (n && !(n & (n - 1)))
		return n;
	
	while( n != 0)
	{
		n >>= 1;
		count += 1;
	}
	
	return 1 << count;
}

// Driver Code
int main()
{
	unsigned int n = 0;
	cout << nextPowerOf2(n);
	return 0;
}
