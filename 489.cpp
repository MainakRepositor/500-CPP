// A Naive Recursive method to find maximum product
#include <iostream>
using namespace std;

// Utility function to get the maximum of two and three integers
int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}

// The main function that returns maximum product obtainable
// from a rope of length n
int maxProd(int n)
{
	// Base cases
	if (n == 0 || n == 1) return 0;

	// Make a cut at different places and take the maximum of all
	int max_val = 0;
	for (int i = 1; i < n; i++)
	max_val = max(max_val, i*(n-i), maxProd(n-i)*i);

	// Return the maximum of all values
	return max_val;
}

/* Driver program to test above functions */
int main()
{
	cout << "Maximum Product is " << maxProd(10);
	return 0;
}
