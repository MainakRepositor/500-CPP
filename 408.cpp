#include<iostream>

using namespace std;

typedef unsigned int uint_t;

// this function returns next higher number with same number of set bits as x.
uint_t snoob(uint_t x)
{

uint_t rightOne;
uint_t nextHigherOneBit;
uint_t rightOnesPattern;

uint_t next = 0;

if(x)
{

	// right most set bit
	rightOne = x & -(signed)x;

	// reset the pattern and set next higher bit
	// left part of x will be here
	nextHigherOneBit = x + rightOne;

	// nextHigherOneBit is now part [D] of the above explanation.

	// isolate the pattern
	rightOnesPattern = x ^ nextHigherOneBit;

	// right adjust pattern
	rightOnesPattern = (rightOnesPattern)/rightOne;

	// correction factor
	rightOnesPattern >>= 2;

	// rightOnesPattern is now part [A] of the above explanation.

	// integrate new pattern (Add [D] and [A])
	next = nextHigherOneBit | rightOnesPattern;
}

return next;
}

int main()
{
int x = 156;
cout<<"Next higher number with same number of set bits is "<<snoob(x);

getchar();
return 0;
}
