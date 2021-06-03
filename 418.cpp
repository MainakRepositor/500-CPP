#include <bits/stdc++.h>
using namespace std;
/* implementation of strcmp that ignores cases */
int ic_strcmp(string s1, string s2)
{
	int i;
	for (i = 0; s1[i] && s2[i]; ++i)
	{
		/* If characters are same or inverting the
		6th bit makes them same */
		if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
		continue;
		else
		break;
	}

	/* Compare the last (or first mismatching in
	case of not same) characters */
	if (s1[i] == s2[i])
		return 0;

	// Set the 6th bit in both, then compare
	if ((s1[i] | 32) < (s2[i] | 32))
		return -1;
	return 1;
}

// Driver program to test above function
int main()
{
	cout<<"ret: "<<ic_strcmp("Geeks", "apple") <<endl;
	cout<<"ret: "<<ic_strcmp("", "ABCD")<<endl;
	cout<<"ret: "<<ic_strcmp("ABCD", "z")<<endl;
	cout<<"ret: "<<ic_strcmp("ABCD", "abcdEghe")<<endl;
	cout<<"ret: "<<ic_strcmp("GeeksForGeeks", "gEEksFORGeEKs")<<endl;
	cout<<"ret: "<<ic_strcmp("GeeksForGeeks", "geeksForGeeks")<<endl;
	return 0;
}

