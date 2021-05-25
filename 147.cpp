// C++ program to count all duplicates
// from string using hashing
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256

class gfg
{
	public :
	
	/* Fills count array with
	frequency of characters */
	void fillCharCounts(char *str, int *count)
	{
		int i;
		for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	}

	/* Print duplicates present
	in the passed string */
	void printDups(char *str)
	{
		
		// Create an array of size 256 and fill
		// count of every character in it
		int *count = (int *)calloc(NO_OF_CHARS,
									sizeof(int));
		fillCharCounts(str, count);

		// Print characters having count more than 0
		int i;
		for (i = 0; i < NO_OF_CHARS; i++)
		if(count[i] > 1)
			printf("%c, count = %d \n", i, count[i]);

		free(count);
	}
};

/* Driver code*/
int main()
{
	gfg g ;
	char str[] = "test string";
	g.printDups(str);
	//getchar();
	return 0;
}


