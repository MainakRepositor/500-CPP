// C++ program to check if a number
// is multiple of 9 using bitwise operators
#include <bits/stdc++.h>
using namespace std;

// Bitwise operator based function to check divisibility by 9
bool isDivBy9(int n)
{
	// Base cases
	if (n == 0 || n == 9)
		return true;
	if (n < 9)
		return false;

	// If n is greater than 9, then recur for [floor(n/9) - n%8]
	return isDivBy9((int)(n >> 3) - (int)(n & 7));
}

// Driver program to test above function
int main()
{
	// Let us print all multiples of 9 from 0 to 100
	// using above method
	for (int i = 0; i < 100; i++)
		if (isDivBy9(i))
			cout << i << " ";
	return 0;
}
