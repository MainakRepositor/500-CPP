// A C++ program to remove "b" and 'ac' from input string
#include <iostream>
using namespace std;
#define ONE 1
#define TWO 2

// The main function that removes occurrences of "a" and "bc"
// in input string
void stringFilter(char *str)
{
	// state is initially ONE (The previous character is not a)
	int state = ONE;

	// i and j are index variables, i is used to read next
	// character of input string, j is used for indexes of output
	// string (modified input string)
	int j = 0;

	// Process all characters of input string one by one
	for (int i = 0; str[i] != '\0'; i++)
	{
		/* If state is ONE, then do NOT copy the current character
		to output if one of the following conditions is true
		...a) Current character is 'b' (We need to remove 'b')
		...b) Current character is 'a' (Next character may be 'c') */
		if (state == ONE && str[i] != 'a' && str[i] != 'b')
		{
			str[j] = str[i];
			j++;
		}

		// If state is TWO and current character is not 'c' (other-
		// wise we ignore both previous and current characters)
		if (state == TWO && str[i] != 'c')
		{
			// First copy the previous 'a'
			str[j] = 'a';
			j++;

			// Then copy the current character if it is not 'a'
			// and 'b'
			if (str[i] != 'a' && str[i] != 'b')
			{
				str[j] = str[i];
				j++;
			}
		}

		// Change state according to current character
		state = (str[i] == 'a')? TWO: ONE;
	}

	// If last character was 'a', copy it to output
	if (state == TWO)
	{
		str[j] = 'a';
		j++;
	}

	// Set the string terminator
	str[j] = '\0';
}

/* Driver program to check above functions */
int main()
{
	char str1[] = "ad";
	stringFilter(str1);
	cout << str1 << endl;

	char str2[] = "acbac";
	stringFilter(str2);
	cout << str2 << endl;

	char str3[] = "aaac";
	stringFilter(str3);
	cout << str3 << endl;

	char str4[] = "react";
	stringFilter(str4);
	cout << str4 << endl;

	char str5[] = "aa";
	stringFilter(str5);
	cout << str5 << endl;

	char str6[] = "ababaac";
	stringFilter(str6);
	cout << str6 << endl;

	return 0;
}
