#include <iostream>
using namespace std;

//adds the two-bit strings and return the result
string addBitStrings( string first, string second );

// Helper method: given two unequal sized bit strings, converts them to
// same length by adding leading 0s in the smaller string. Returns the
// the new length
int makeEqualLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0 ; i < len2 - len1 ; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 = '0' + str2;
	}
	return len1; // If len1 >= len2
}

// The main function that adds two-bit sequences and returns the addition
string addBitStrings( string first, string second )
{
	string result; // To store the sum bits

	// make the lengths same before adding
	int length = makeEqualLength(first, second);

	int carry = 0; // Initialize carry

	// Add all bits one by one
	for (int i = length-1 ; i >= 0 ; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';

		// boolean expression for sum of 3 bits
		int sum = (firstBit ^ secondBit ^ carry)+'0';

		result = (char)sum + result;

		// boolean expression for 3-bit addition
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}

	// if overflow, then add a leading 1
	if (carry)
		result = '1' + result;

	return result;
}

// Driver program to test above functions
int main()
{
	string str1 = "1100011";
	string str2 = "10";

	cout << "Sum is " << addBitStrings(str1, str2);
	return 0;
}
