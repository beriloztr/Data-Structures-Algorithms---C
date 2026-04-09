/* LG13_2 -> Palindrome */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

//function to find whether a string given is palindrome or not
int palindrome(char *sent);

int main(void)
{
	char sent[SIZE], temp[SIZE];
	int result;

	printf("Enter a word: ");
	scanf("%s", sent);

	strcpy(temp, sent);
	result = palindrome(temp); // do NOT destroy the original string, so send temp to the function

	if (result == 1)
		printf("\nThe word <%s> was a palindrome.\n", sent);
	else
		printf("\nThe word <%s> was NOT a palindrome.\n", sent);


	return 0;
}

int palindrome(char *str)
{
	int len = strlen(str);

	//until the last letter, compare each with their mirror
	if (len <= 1)
		return 1;
	else
	{
		//if the current letter isn't the same as its mirror then not palindrome
		if (*(str) != *(str + len - 1))
			return 0;
		else
		{
			*(str + len - 1) = '\0';
			return palindrome(str + 1);
		}
	}
}