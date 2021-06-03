#include <bits/stdc++.h>
using namespace std;
void changeToZero(int a[2])
{
	a[ a[1] ] = a[ !a[1] ];
}

// Driver code
int main()
{
	int a[] = {1, 0};
	changeToZero(a);
	
	cout<<"arr[0] = "<<a[0]<<endl;
	cout<<" arr[1] = "<<a[1];
	return 0;
}


