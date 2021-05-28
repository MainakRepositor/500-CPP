// C++ implimentation of above approach
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap characters
void swap ( char* a, char* b )
{
	char t = *a;
	*a = *b;
	*b = t;
}

// A utility function to reverse string str[low..high]
void reverse ( char* str, int low, int high )
{
	while ( low < high )
	{
		swap( &str[low], &str[high] );
		++low;
		--high;
	}
}

// Cycle leader algorithm to move all even
// positioned elements at the end.
void cycleLeader ( char* str, int shift, int len )
{
	int j;
	char item;

	for (int i = 1; i < len; i *= 3 )
	{
		j = i;

		item = str[j + shift];
		do
		{
			// odd index
			if ( j & 1 )
				j = len / 2 + j / 2;
			// even index
			else
				j /= 2;

			// keep the back-up of element at new position
			swap (&str[j + shift], &item);
		}
		while ( j != i );
	}
}

// The main function to transform a string. This function
// mainly uses cycleLeader() to transform
void moveNumberToSecondHalf( char* str )
{
	int k, lenFirst;

	int lenRemaining = strlen( str );
	int shift = 0;

	while ( lenRemaining )
	{
		k = 0;

		// Step 1: Find the largest prefix
		// subarray of the form 3^k + 1
		while ( pow( 3, k ) + 1 <= lenRemaining )
			k++;
		lenFirst = pow( 3, k - 1 ) + 1;
		lenRemaining -= lenFirst;

		// Step 2: Apply cycle leader algorithm
		// for the largest subarrau
		cycleLeader ( str, shift, lenFirst );

		// Step 4.1: Reverse the second half of first subarray
		reverse ( str, shift / 2, shift - 1 );

		// Step 4.2: Reverse the first half of second sub-string.
		reverse ( str, shift, shift + lenFirst / 2 - 1 );

		// Step 4.3 Reverse the second half of first sub-string
		// and first half of second sub-string together
		reverse ( str, shift / 2, shift + lenFirst / 2 - 1 );

		// Increase the length of first subarray
		shift += lenFirst;
	}
}

// Driver program to test above function
int main()
{
	char str[] = "a1b2c3d4e5f6g7";
	moveNumberToSecondHalf( str );
	cout<<str;
	return 0;
}


