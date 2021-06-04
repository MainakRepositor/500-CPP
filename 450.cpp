// An efficient C++ program to randomly select
// a number from stream of numbers.
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// A function to randomly select a item
// from stream[0], stream[1], .. stream[i-1]
int selectRandom(int x)
{
	static int res; // The resultant random number
	static int count = 0; // Count of numbers visited
						// so far in stream

	count++; // increment count of numbers seen so far

	// If this is the first element from stream,
	// return it
	if (count == 1)
		res = x;
	else
	{
		// Generate a random number from 0 to count - 1
		int i = rand() % count;

		// Replace the prev random number with
		// new number with 1/count probability
		if (i == count - 1)
			res = x;
	}
	return res;
}

// Driver Code
int main()
{
	int stream[] = {1, 2, 3, 4};
	int n = sizeof(stream) / sizeof(stream[0]);

	// Use a different seed value for every run.
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		cout << "Random number from first " << i + 1
			<< " numbers is " << selectRandom(stream[i]) << endl;
	return 0;
}
