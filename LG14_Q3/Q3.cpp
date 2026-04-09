#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_struct.h"
#define SIZE 50

void display(stack_t S, int size)
{
	SType temp;
	printf("There are %d competitions\n", size);
	printf("Competition Name                  Start Time                        End Time\n");
	printf("******************************************************************************\n");
	
	for (int i = 0; i<size; i++)
	{
		temp = pop(&S);
		printf("%-35s %35s %35s\n", temp.name, temp.start, temp.end);
	}
}

int main(void)
{
	FILE* inp;
	inp = fopen("Competitions.bin", "rb");
	if (inp == NULL)
		printf("Cannot open the file.\n");
	else {
		stack_t S;
		initializeS(&S);
		SType comp;
		int n; // nb of the comps
		fseek(inp,0, SEEK_END);
		n = ftell(inp) / sizeof(SType);
		rewind(inp);

		for (int i = 0; i < n; i++)
		{
			fread(&comp, sizeof(SType), 1, inp);
			push(&S, comp);
		}
		display(S, n);
		fclose(inp);
	}
	return 0;
}