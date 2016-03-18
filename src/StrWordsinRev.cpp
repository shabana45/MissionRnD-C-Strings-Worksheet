/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void rev1(char* str, int first, int last);
void str_words_in_rev(char *input, int len){
	int first = 0, last = len - 1;
	int i = 0, j = 0;
	rev1(input, first, last);
	while (input[i] != '\0')
	{
		if (input[j] == ' ' || input[j] == '\0')
		{
			rev1(input, i, j - 1);
			i = j + 1;
			j = i;
		}
		else
		{
			j++;
		}
	}

}
void rev1(char* str, int first, int last)
{

	while (first<last)
	{
		str[first] ^= str[last];
		str[last] ^= str[first];
		str[first] ^= str[last];
		++first;
		--last;
	}
}