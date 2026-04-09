#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define SIZE 100

/*
Author: Beril Ozturk
AQ: Write a program that reads numbers from a text file into a two dimensional integer array.
There are 5 columns in each row, while the number of rows is unknown.
If the matrix is square, the program will calculate the sum of the elements on the minor diagonal,
otherwise it will calculate the product of elements in the given row.
Use the following functions:

* display: Display all elements in the matrix.
* sumOfMinor: Find the sum of the elements on the minor diagonal of the matrix.
* productOfRow: Find the product of the elements on a specified row.

Project Name: LG01_AQ
File Name: Q4.cpp
*/

int sumOfMinor(int num[][5])
{
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += num[i][4 - i];

	}
	return(sum);

}

int productOfRow(int num[][5], int row)
{
	int product = 1;

	for (int i = 0; i < 5; i++)
	{
		product *= num[row][i];

	}

	return(product);
}


int main(void)
{
	int num[SIZE][5], i = 0, sum, product;
	FILE* inp;
	inp = fopen("input2.txt", "r");

	if (inp == NULL)
		printf("cannot open the file.");

	else
	{
		int i = 0;
		while (fscanf(inp, " %d %d %d %d %d", &num[i][0], &num[i][1], &num[i][2], &num[i][3], &num[i][4]) != EOF)
		{
			i++;
		}

		if (i == 5)
		{
			sum = sumOfMinor(num);
			printf("The matrix is a SQUARE matrix\n");
			printf("The sum of the elements on the Minor Diagonal is : %d\n", sum);
		}

		else
		{
			int r;

			printf("The matrix is not a SQUARE matrix\n");
			printf("Enter the row number : ");
			scanf("%d", &r);
			product = productOfRow(num, r - 1);
			printf("The product of the elements on the given row : %d\n", product);

		}

		fclose(inp);
	}


	return 0;
}