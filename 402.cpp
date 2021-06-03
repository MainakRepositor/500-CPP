#include<stdio.h>

// This function will return n % d.
// d must be one of: 1, 2, 4, 8, 16, 32, …
unsigned int getModulo(unsigned int n,
					unsigned int d)
{
return ( n & (d - 1) );
}		

// Driver Code
int main()
{
unsigned int n = 6;

// d must be a power of 2
unsigned int d = 4;
printf("%u moduo %u is %u", n, d, getModulo(n, d));

getchar();
return 0;
}	
