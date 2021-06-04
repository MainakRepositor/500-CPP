#include <iostream>
using namespace std;

// A method to multiply two numbers using Russian Peasant method
unsigned int russianPeasant(unsigned int a, unsigned int b)
{
	int res = 0; // initialize result

	// While second number doesn't become 1
	while (b > 0)
	{
		// If second number becomes odd, add the first number to result
		if (b & 1)
			res = res + a;

		// Double the first number and halve the second number
		a = a << 1;
		b = b >> 1;
	}
	return res;
}

// Driver program to test above function
int main()
{
	cout << russianPeasant(18, 1) << endl;
	cout << russianPeasant(20, 12) << endl;
	return 0;
}
