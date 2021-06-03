// C++ program to find sum of series
#include <iostream>
using namespace std;

// Function to return sum of
// 1/1 + 1/2 + 1/3 + ..+ 1/n
class gfg
{
	
public : double sum(int n)
{
	double i, s = 0.0;
	for (i = 1; i <= n; i++)
	s = s + 1/i;
	return s;
}
};

// Driver code
int main()
{
	gfg g;
	int n = 5;
	cout << "Sum is " << g.sum(n);
	return 0;
}


