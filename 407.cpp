// C++ code to add add
// one to a given number
#include <bits/stdc++.h>
using namespace std;

int addOne(int x)
{
	int m = 1;
	
	// Flip all the set bits
	// until we find a 0
	while( x & m )
	{
		x = x ^ m;
		m <<= 1;
	}
	
	// flip the rightmost 0 bit
	x = x ^ m;
	return x;
}

/* Driver program to test above functions*/
int main()
{
	cout<<addOne(13);
	return 0;
}


