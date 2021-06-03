// C++ program to Multiply two integers without
// using multiplication, division and bitwise
// operators, and no loops
#include<iostream>

using namespace std;
class GFG
{
	
/* function to multiply two numbers x and y*/
public : int multiply(int x, int y)
{
	/* 0 multiplied with anything gives 0 */
	if(y == 0)
	return 0;

	/* Add x one by one */
	if(y > 0 )
	return (x + multiply(x, y-1));

	/* the case where y is negative */
	if(y < 0 )
	return -multiply(x, -y);
}
};

// Driver code
int main()
{
	GFG g;
	cout << endl << g.multiply(5, -11);
	getchar();
	return 0;
}

