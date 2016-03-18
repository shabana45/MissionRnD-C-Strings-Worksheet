/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
#include <stdio.h>
#include <malloc.h>

#define SIZE 31
int compare(char str1[][100], char str2[][100], int i, int j);
char **commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int i, count = 0;
	for (i = 0; str1[i] != '\0'; i++){
		if (str1[i] == ' ')
			count++;
	}
	if (i == count)
		return NULL;
	int  count1 = 0;
	for (i = 0; str2[i] != '\0'; i++){
		if (str2[i] == ' ')
			count++;
	}
	if (i == count1)
		return NULL;

	char str1Words[100][100];
	char str2Words[100][100];
	int countStr1, countStr2;
	int  k = 0, j = 0;
	i = 0;
	char **res = (char**)malloc(100 * sizeof(char *));
	for (i = 0; i<31; i++){
		res[i] = (char*)malloc(31 * sizeof(char *));
	}
	i = 0;
	if (str1[0] == ' ')
		i = 1;
	else
		i = 0;
	while (str1[i] != '\0'){
		if (str1[i] == ' '){
			str1Words[j][k] = '\0';
			j++;
			k = 0;
		}
		else{
			str1Words[j][k++] = str1[i];
		}
		i++;
	}
	str1Words[j][k] = '\0';
	countStr1 = j;
	i = 0; k = 0; j = 0;
	if (str2[0] == ' ')
		i = 1;
	else
		i = 0;
	while (str2[i] != '\0'){
		if (str2[i] == ' '){
			str2Words[j][k] = '\0';
			j++;
			k = 0;
		}
		else{
			str2Words[j][k++] = str2[i];
		}
		i++;
	}
	str2Words[j][k] = '\0';
	countStr2 = j;
	int t = 0;

	for (i = 0; i <= countStr1; i++){
		for (j = 0; j <= countStr2; j++){
			if (compare(str1Words, str2Words, i, j) == 0){
				int k, j;

				k = j = 0;

				while (str1Words[i][j] != '\0'){

					res[t][k++] = str1Words[i][j++];

				}

				res[t][k] = '\0';

				t++;

			}
		}
	}

	if (t == 0)
		return NULL;
	else
		return res;



}

int compare(char str1[][100], char str2[][100], int i, int j)
{
	int k = 0;
	int  match = 0;
	while (str1[i][k] != '\0'&&str2[j][k] != '\0') {
		if (str1[i][k] != str2[j][k]){
			match = -1;
			break;
		}
		k++;
	}

	if (match == 0) return 0;

	else return -1;

}