// LG16_Q3 -> Finds and displays the palindrome sentences in the file

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack_char.h"

#define SIZE 100

int palindrome(char* sent);
int isLetter(char ch);
void removePunct(char* sent);

int main(void)
{
	FILE* inp = fopen("palindrome.txt", "r");

	if (inp == NULL)
		printf("\nFile can not be opened!\n");
	else
	{
		char sent[SIZE];
		int status;

		while (fscanf(inp, "%[^\n] ", sent) != EOF)
		{
			removePunct(sent);
			if (palindrome(sent))
				printf("%s\n", sent);
		}
	}
	printf("\n\n");
	return(0);
}

int palindrome(char* sent)
{
	int i, len = strlen(sent);
	char value;

	stack_t st;
	initializeS(&st);

	for (i = 0; i < len / 2; i++)
		push(&st, sent[i]);

	if (len % 2 == 1)
		i++;

	//pop a value from the stack which is the last character of the sentence
	value = pop(&st);


	//check if the popped value is equal to the current character
	while (i <= len && toupper(value) == toupper(sent[i]))
	{
		i++;

		if (!isEmptyS(&st))						//if the stack is NOT empty, pop a value
			value = pop(&st);
	}

	//if i is equal to length of the sentence, we can say the sentence is palindrome
	if (i == len)
		return 1;
	else
		return 0;
}

int isLetter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;

	return 0;
}

void removePunct(char* sent)
{
	int len = strlen(sent), st;

	int i = 0, k = 0;
	while (i < len)
	{
		while (isLetter(sent[i]))
			i++;

		st = i;
		while (i < len && !isLetter(sent[i]))
			i++;

		strcpy(sent + st, sent + i);
	}
}
