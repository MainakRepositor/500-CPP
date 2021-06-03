// C++ program to multiply
// a number with 3.5
#include <bits/stdc++.h>

int multiplyWith3Point5(int x)
{
	return (x<<1) + x + (x>>1);
}

/* Driver program to test above functions*/
int main()
{
	int x = 4;
	printf("%d", multiplyWith3Point5(x));
	getchar();
	return 0;
}
