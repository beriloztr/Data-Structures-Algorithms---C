/* LG13_Q4 -> Ackerman */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int isAckermann(int m, int n);

int main(void)
{
	int	m, n;

	printf("Enter the value of m: ");
	scanf("%d", &m);

	printf("Enter the value of n: ");
	scanf("%d", &n);

	if (m >= 0 && n >= 0)
	{
		if (m >= 4)
			printf("\nThe value of the m had to be less than 4. Exiting.\n");
		else
			printf("\nThe result is %d\n", isAckermann(m, n));
	}
	else
		printf("\nThe value of both m & n had to be positive values. Exiting.\n");

	return(0);
}

int isAckermann(int m, int n)
{
	//if num is 0 then n should be increased
	if (m == 0)
		return n + 1;
	else
		if (n == 0)
			return isAckermann(m - 1, 1);
		else
			return isAckermann(m - 1, isAckermann(m, n - 1));
}