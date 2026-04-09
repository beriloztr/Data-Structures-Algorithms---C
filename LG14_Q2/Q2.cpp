#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_int.h"

void display(stack_t S) {
	while (isEmptyS(&S) == 0)
	{
		SType temp[20];
		strcpy(temp, pop(&S));
		printf("%s\n", temp);
	}

}
int main(void)
{
	FILE* inp;
	inp = fopen("dept.bin", "rb");
	if (inp == NULL)
		printf("Cannot open the file.");
	else {
		int n;
		fseek(inp, 0, SEEK_END);
		n = ftell(inp)/ sizeof(char);
		rewind(inp);
		stack_t S;
		initializeS(&S);
		SType name[20];

		//
		while (fread(name, sizeof(SType) * 20, 1, inp) == 1 && !isFullS(&S))
		{
			push(&S, name);
		}

		printf("DEPARTMENTS IN REVERSE ORDER\n***********************\n");
		display(S);
		//while (isEmptyS(&S)==0)
		//{
		//	SType temp[20];
		//	strcpy(temp,pop(&S));
		//	printf("%s\n", temp);
		//}
		fclose(inp);
	}
	return 0;
}