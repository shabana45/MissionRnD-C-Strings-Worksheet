/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/
#include <stdio.h>
int int_str(char *str, int num, int x);
int int_str1(char *str, int num, int x);
void rev(char *str, int first, int last);
int int_str1(char *str, int num, int i)
{
	int t;
	while (num != 0){
		t = num % 10;
		str[i++] = t + '0';
		num = num / 10;
	}
	return i;
}
int int_str(char *str, int num, int i)
{
	int t;
	while (num != 0){
		t = num % 10;
		str[++i] = t + '0';
		num = num / 10;
	}
	return i;
}

void rev(char *str, int first, int last){
	int temp;
	while (first< last){
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}

}


void number_to_str(float number, char *str, int afterdecimal){
	int num = number;
	float floa = num - number;
	if (number > 0){
		int num = (int)number;
		float x = number - (float)num;
		if (number - num != 0){
			int i;
			i = int_str1(str, num, 0);
			rev(str, 0, i - 1);
			str[i] = '.';
			int u = i + 1;
			while (afterdecimal--){
				x = x * 10;
			}
			i = int_str(str, x, i);
			str[++i] = '\0';
			rev(str, u, i - 1);

		}
		else if (number - num == 0 && number > 0){
			int i;
			i = int_str1(str, num, 0);;
			rev(str, 0, i - 1);
			str[i] = '\0';
		}
	}
	else if (number < 0){
		number = (-1)*number;
		int i;
		int num = (int)number;
		float x = number - (float)num;
		if (number - num == 0){
			str[0] = '-';
			i = int_str1(str, num, 1);
			rev(str, 1, i - 1);
			str[i] = '\0';
		}

		else if (number - num != 0){
			int i;
			int num = (int)number;
			float floa = number - (float)num;
			str[0] = '-';
			i = int_str1(str, num, 1);
			rev(str, 1, i - 1);
			str[i] = '.';
			int u = i + 1;
			while (afterdecimal--){
				floa *= 10;
			}
			i = int_str(str, floa, i);
			str[++i] = '\0';
			rev(str, u, i - 1);


		}
	}
}