/* LG16_Q1 -> Finds odd numbers and inserts these numbers to the queue */

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include "queue_int.h"

void displayQueue(queue_t queue);

int main(void)
{
	int value;

	queue_t myqueue;
	initializeQ(&myqueue);

	printf("Enter a number (or negative to STOP) : ");
	scanf("%d", &value);

	while (value > 0)
	{
		if (value % 5 == 0)
			insert(&myqueue, value);

		printf("Enter a number (or negative to STOP) : ");
		scanf("%d", &value);
	}

	displayQueue(myqueue);

	printf("\n");

	return 0;
}

void displayQueue(queue_t queue)
{
	printf("\nQueue Content\n");
	printf("--------------------------\n");

	while (!isEmptyQ(&queue))
		printf("%d\t", remove(&queue));
}