/* LG14_Q1 -> Display the digits of a given number using an int stack */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "stack_int.h"

int main(void)
{
	int num;
	stack_t s;

	do
	{
		printf("Enter a four-digit number: ");
		scanf("%d", &num);
	} while (num < 1000 || num > 9999);

	//initialize the stack so that it can be used
	initializeS(&s);

	printf("\n Digits of %d are ", num);

	//fill the stack with the digits of the number
	while (num != 0)
	{
		push(&s, num % 10);
		num /= 10;
	}

	//print out the elements of the stack until such time that it is empty\
				because the stack is emptied in reverse of how it was filled, the digits\
	of the number printed out will be in the correct order
	while (!isEmptyS(&s))
		printf("%d ", pop(&s));

	printf("\n");

	return (0);
}