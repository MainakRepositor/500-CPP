#include <bits/stdc++.h>
using namespace std;

// unsets the rightmost set bit
// of n and returns the result
int fun(unsigned int n)
{
	return n & (n - 1);
}

// Driver Code
int main()
{
	int n = 7;
	cout<<"The number after unsetting the";
	cout<<" rightmost set bit "<<fun(n);
	return 0;
}


