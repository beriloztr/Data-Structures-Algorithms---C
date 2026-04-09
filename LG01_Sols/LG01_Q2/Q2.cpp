#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define SIZE 100

/*
Author: Beril Ozturk
Q2: Write a C program that reads positive numbers and stores them in an integer array,
and finds the count of even and odd numbers using the functions below.

  fillArray: takes an array as a parameter, reads the positive numbers from the 
user and stores them in the array, and returns the actual number of elements.

  findEvenOdd: takes an integer array and its size as a parameters, and finds and 
returns the count of even and odd numbersin the array.

Project Name: LG01_Q2
File Name: Q2.cpp
*/

int fillArray(int num[], int size)
{

	printf("Enter a positive number: ");
	scanf("%d", &num[size]);

	while (num[size] > 0)
	{
		size += 1;
		printf("Enter a positive number: ");
		scanf("%d", &num[size]);

	}

	return (size);
}


void findEvenOdd(int num[], int size, int *even, int *odd)
{
	for (int i = 0; i < size; i++)
	{
		if (num[i] % 2 == 0)
			(*even)++;

		
		else
			(*odd)++;

	}
	
}


int main(void)
{
	int size = 0, num[SIZE];
	int even = 0, odd = 0;

	size = fillArray(num, size);
	findEvenOdd(num, size, &even, &odd);

	printf("There are %d even numbers\n", even);
	printf("There are %d odd numbers\n", odd);

	return 0;
}


