// C++ program to print all strings that contain all
// characters of a word
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;
# define NO_OF_CHARS 256

/* prints list items having all caharacters of word */
void print(char list[][50], char *word, int list_size)
{
	/*Since calloc is used, map[] is initialized as 0 */
	int *map = new int[(sizeof(int)*NO_OF_CHARS)];
	int i, j, count, word_size;

	/*Set the values in map */
	for (i = 0; *(word+i); i++)
		map[*(word + i)] = 1;

	/* Get the length of given word */
	word_size = strlen(word);

	/* Check each item of list if has all characters
	of word*/
	for (i = 0; i < list_size; i++)
	{
		for (j = 0, count = 0; *(list[i] + j); j++)
		{
			if (map[*(list[i] + j)])
			{
				count++;

				/* unset the bit so that strings like
				sss not printed*/
				map[*(list[i] + j)] = 0;
			}
		}
		if (count == word_size)
			cout << list[i] << endl;

		/*Set the values in map for next item*/
		for (j = 0; *(word + j); j++)
			map[*(word + j)] = 1;
	}
}

/* Driver code*/
int main()
{
	char str[] = "sun";
	char list[][50] = {"geeksforgeeks", "unsorted", "sunday",
					"just", "sss" };
	print(list, str, 5);
	return 0;
}


