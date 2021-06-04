// C++ Efficient program to calculate
// e raise to the power x
#include <bits/stdc++.h>
using namespace std;

// Returns approximate value of e^x
// using sum of first n terms of Taylor Series
float exponential(int n, float x)
{
	float sum = 1.0f; // initialize sum of series

	for (int i = n - 1; i > 0; --i )
		sum = 1 + x * sum / i;

	return sum;
}

// Driver code
int main()
{
	int n = 10;
	float x = 1.0f;
	cout << "e^x = " << fixed << setprecision(5) << exponential(n, x);
	return 0;
}


