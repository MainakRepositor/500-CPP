#include <bits/stdc++.h>
using namespace std;
#define CHARBIT 8

/* This function will return absolute value of n*/
unsigned int getAbs(int n)
{
	int const mask = n >> (sizeof(int) * CHARBIT - 1);
	return ((n + mask) ^ mask);
}

/* Driver program to test above function */
int main()
{
	int n = -6;
	cout << "Absoute value of " << n << " is " << getAbs(n);
	return 0;
}


