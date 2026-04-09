// LG16_Q2 -> Reads some commands from the text files and do the tasks

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include "stack_struct.h
#define SIZE 20

void display(stack_t s);

int main(void)
{
	FILE *inp;
	char cmd[SIZE];
	int status;
	stack_t st;
	person_t per;

	inp = fopen("commands.txt", "r");

	if (inp == NULL)
		printf("Error in opening file");
	else
	{
		initializeS(&st);

		status = fscanf(inp, "%s", cmd);

		while (status != EOF)
		{
			if (strcmp(cmd, "Push") == 0)
			{
				status = fscanf(inp, "%s %d", per.name, &per.age);
				if (!isFullS(&st))
					push(&st, per);
				else
					printf("Sorry stack is full!\n\n");
			}
			else if (strcmp(cmd, "Pop") == 0)
			{
				if (!isEmptyS(&st))
				{
					per = pop(&st);
					printf("\n%s and %d is removed from the stack\n", per.name, per.age);
				}
				else
					printf("\nSorry stack is empty!\n");
			}
			else if (strcmp(cmd, "Display") == 0)
				display(st);

			status = fscanf(inp, "%s", cmd);
		}

		fclose(inp);
	}

	return(0);
}

void display(stack_t s)
{
	person_t temp;

	printf("\nStack content is\n");

	while (!isEmptyS(&s))
	{
		temp = pop(&s);
		printf("%s\t%d\n", temp.name, temp.age);
	}
}