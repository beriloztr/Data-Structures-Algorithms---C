#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Author: Beril Ozturk
Q1:Write a C program that will generate n (will be given by user) random numbers (between 100 - 999), then the program writes each generated number and the digits of that number in reverse order into the file reverse.txt.
Project Name: LG1_Q1
File Name: Q1.cpp
*/

int main(void)
{
	int n, num, digit;
	FILE* inp;
	inp = fopen("reverse.txt", "w");
	//n represents the nb of lines the numbers will be printed (number count).


	printf("How many numbers will you generate: ");
	scanf("%d", &n);

	srand(time(NULL));

	fprintf(inp, "Generated number\tDigits in reverse order\n");
	fprintf(inp, "****************\t***********************\n");


	for (int i = 0; i < n; i++)
	{
		//Generating random number (n times in this for loop)
		num = rand() % 900 + 100;
		fprintf(inp, "%d\t", num);

		//writing the number in a reversed way
		for (int j = 0; j < 3; j++) 
		{
			digit = num - num / 10 * 10;
			fprintf(inp, "%d\t", digit);
			num = num / 10;
		}
		fprintf(inp, "\n");
	}
	fclose(inp);
	printf("%d numbers and their digits in reverse order were written to reverse.txt file.", n);

		return 0;
}