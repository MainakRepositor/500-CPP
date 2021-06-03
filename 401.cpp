// C++ program to Compute the minimum
// or maximum of two integers without
// branching
#include<iostream>
using namespace std;

class gfg
{
	
	/*Function to find minimum of x and y*/
	public:
	int min(int x, int y)
	{
		return y ^ ((x ^ y) & -(x < y));
	}

	/*Function to find maximum of x and y*/
	int max(int x, int y)
	{
		return x ^ ((x ^ y) & -(x < y));
	}
	};
	
	/* Driver code */
	int main()
	{
		gfg g;
		int x = 15;
		int y = 6;
		cout << "Minimum of " << x <<
			" and " << y << " is ";
		cout << g. min(x, y);
		cout << "\nMaximum of " << x <<
				" and " << y << " is ";
		cout << g.max(x, y);
		getchar();
	}


