#include <bits/stdc++.h>
using namespace std;

/* Takes pointer to result and two numbers as
	arguments. If there is no overflow, the function
	places the resultant = sum a+b in “result” and
	returns 0, otherwise it returns -1 */
int addOvf(int* result, int a, int b)
{
	*result = a + b;
	if(a > 0 && b > 0 && *result < 0)
		return -1;
	if(a < 0 && b < 0 && *result > 0)
		return -1;
	return 0;
}

// Driver code
int main()
{
	int *res = new int[(sizeof(int))];
	int x = 2147483640;
	int y = 10;

	cout<<addOvf(res, x, y);

	cout<<"\n"<<*res;
	return 0;
}
