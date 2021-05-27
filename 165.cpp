// C++ program to check if given string is
// an interleaving of the other two strings
#include <bits/stdc++.h>
using namespace std;

// Returns true if C is an interleaving of A and B,
// otherwise returns false
bool isInterleaved (char A[], char B[], char C[])
{
	// Iterate through all characters of C.
	while (*C != 0)
	{
		// Match first character of C with first character
		// of A. If matches them move A to next
		if (*A == *C)
			A++;

		// Else Match first character of C with first
		// character of B. If matches them move B to next
		else if (*B == *C)
			B++;

		// If doesn't match with either A or B, then return
		// false
		else
			return false;
		
		// Move C to next for next iteration
		C++;
	}

	// If A or B still have some characters, then length of
	// C is smaller than sum of lengths of A and B, so
	// return false
	if (*A || *B)
		return false;

	return true;
}

// Driver program to test above functions
int main()
{
	char A[] = "AB";
	char B[] = "CD";
	char C[] = "ACBG";
	if (isInterleaved(A, B, C) == true)
		cout << C << " is interleaved of " << A << " and " << B;
	else
		cout << C << " is not interleaved of " << A << " and " << B;

	return 0;
}

