// C++ program to find whether a given
// number is a power of 4 or not
#include<iostream>

using namespace std;
#define bool int

class GFG
{
	
/* Function to check if x is power of 4*/
public : bool isPowerOfFour(int n)
{
	if(n == 0)
		return 0;
	while(n != 1)
	{
		if(n % 4 != 0)
			return 0;
		n = n / 4;
	}
	return 1;
}
};

/*Driver code*/
int main()
{
	GFG g;
	int test_no = 64;
	if(g.isPowerOfFour(test_no))
		cout << test_no << " is a power of 4";
	else
		cout << test_no << "is not a power of 4";
	getchar();
}

