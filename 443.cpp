// C++ program to Generate integer from
// 1 to 5 with equal probability
#include <stdio.h>

// given method that returns 1 to 5 with equal probability
int foo()
{
	// some code here
}

int my_rand() // returns 1 to 7 with equal probability
{
	int i;
	i = 5*foo() + foo() - 5;
	if (i < 22)
		return i%7 + 1;
	return my_rand();
}
// Driver code
int main()
{
	printf ("%d ", my_rand());
	return 0;
}
