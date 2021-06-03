#include <bits/stdc++.h>
using namespace std;
# define bool int

int getNumeralValue(char );
char getNumeral(int );

/* Function to add two numbers in base 14 */
char *sumBase14(char num1[], char num2[])
{
	int l1 = strlen(num1);
	int l2 = strlen(num2);
	char *res;
	int i;
	int nml1, nml2, res_nml;
	bool carry = 0;
		
	if(l1 != l2)
	{
		cout << "Function doesn't support numbers of different"
				" lengths. If you want to add such numbers then"
				" prefix smaller number with required no. of zeroes";
		assert(0);
	}
	
	/* Note the size of the allocated memory is one
		more than i/p lenghts for the cases where we
		have carry at the last like adding D1 and A1 */
	res = new char[(sizeof(char)*(l1 + 1))];
			
	/* Add all numerals from right to left */
	for(i = l1-1; i >= 0; i--)
	{
		/* Get decimal values of the numerals of
		i/p numbers*/
		nml1 = getNumeralValue(num1[i]);
		nml2 = getNumeralValue(num2[i]);
		
		/* Add decimal values of numerals and carry */
		res_nml = carry + nml1 + nml2;
		
		/* Check if we have carry for next addition
			of numerals */
		if(res_nml >= 14)
		{
			carry = 1;
			res_nml -= 14;
		}
		else
		{
			carry = 0;
		}
		res[i+1] = getNumeral(res_nml);
	}
		
	/* if there is no carry after last iteration
		then result should not include 0th character
		of the resultant string */
	if(carry == 0)
		return (res + 1);
	
	/* if we have carry after last iteration then
		result should include 0th character */
	res[0] = '1';
	return res;
}

/* Function to get value of a numeral
For example it returns 10 for input 'A'
1 for '1', etc */
int getNumeralValue(char num)
{
	if( num >= '0' && num <= '9')
		return (num - '0');
	if( num >= 'A' && num <= 'D')
		return (num - 'A' + 10);
			
	/* If we reach this line caller is giving
		invalid character so we assert and fail*/
	assert(0);
}

/* Function to get numeral for a value.
For example it returns 'A' for input 10
'1' for 1, etc */
char getNumeral(int val)
{
	if( val >= 0 && val <= 9)
		return (val + '0');
	if( val >= 10 && val <= 14)
		return (val + 'A' - 10);
		
	/* If we reach this line caller is giving
		invalid no. so we assert and fail*/
	assert(0);
}

/*Driver code*/
int main()
{
	char num1[] = "DC2";
	char num2[] = "0A3";

	cout<<"Result is "<<sumBase14(num1, num2);
	return 0;
}

