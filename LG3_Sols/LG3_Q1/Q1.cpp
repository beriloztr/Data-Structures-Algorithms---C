/* LG3_Q1 -> Checks the results */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double array[4][3] = { { 21.70, 43.71, 14.30 }, { 39.21, 25.97, 55.18 }, { 77.18, 82.7, 54.89 }, { 37.51, 41.99, 22.22 } };

	printf("\nValue represented by \"matrix\" is %p", array);
	printf("\nValue represented by (matrix + 1) is %p", (array + 1));
	printf("\nValue represented by *(matrix + 1) is %p", *(array + 1));
	printf("\nValue represented by (*(matrix) + 1) is %p", (*(array)+1));
	printf("\nValue represented by *(*(matrix) + 1) is %.2f", *(*(array)+1));
	printf("\nValue represented by *(*(matrix + 1)) is %.2f", *(*(array + 1)));
	printf("\nValue represented by *(*(matrix) + 1)+2 is %.2f", *(*(array)+1) + 2);
	printf("\nValue represented by (*(matrix + 1)+2) is %p", (*(array + 1) + 2));
	printf("\nValue represented by *(*(matrix+1) + 2) is %.2f\n", *(*(array + 1) + 2));
}

/*
Value represented by "matrix" is 00CFFC2C
Value represented by (matrix + 1) is 00CFFC44
Value represented by *(matrix + 1) is 00CFFC44
Value represented by (*(matrix) + 1) is 00CFFC34
Value represented by *(*(matrix) + 1) is 43.71
Value represented by *(*(matrix + 1)) is 39.21
Value represented by *(*(matrix) + 1)+2 is 45.71
Value represented by (*(matrix + 1)+2) is 00CFFC54
Value represented by *(*(matrix+1) + 2) is 55.18
*/

