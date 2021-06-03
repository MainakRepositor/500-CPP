// C++ Program to find the area
// of triangle
#include <bits/stdc++.h>
using namespace std;

float findArea(float a, float b, float c)
{
	// Length of sides must be positive
	// and sum of any two sides
	// must be smaller than third side.
	if (a < 0 || b < 0 || c < 0 ||
	(a + b <= c) || a + c <= b ||
					b + c <= a)
	{
		cout << "Not a valid trianglen";
		exit(0);
	}
	float s = (a + b + c) / 2;
	return sqrt(s * (s - a) *
					(s - b) * (s - c));
}

// Driver Code
int main()
{
	float a = 3.0;
	float b = 4.0;
	float c = 5.0;

	cout << "Area is " << findArea(a, b, c);
	return 0;
}
