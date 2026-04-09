/* LG16_Q2 -> Bus Stop */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue_str.h"
#define SIZE 20

void displayQueue(queue_t q);

int main(void)
{
	FILE* inp;
	char name[SIZE];
	int	n, i, status;

	queue_t passengers;
	initializeQ(&passengers);

	inp = fopen("busstop.txt", "r");

	if (inp == NULL)
		printf("File can not be opened");
	else
	{

		//read names of the passengers from the file and insert all the passengers into the queue
		status = fscanf(inp, "%s", name);

		while (status != EOF)
		{
			insert(&passengers, name);
			status = fscanf(inp, "%s", name);
		}

		displayQueue(passengers);

		//remove n passengers from the queue
		printf("\nThe bus arrived to the bus stop!\nHow many passengers getting on the bus? ");
		scanf("%d", &n);

		i = 1;
		printf("\nThe list of passengers getting on the bus:\n");
	}
	while (!isEmptyQ(&passengers) && i <= n)
	{
		strcpy(name, remove(&passengers));
		printf("%s\n", name);
		i++;
	}

	displayQueue(passengers);

	return 0;
}

void displayQueue(queue_t q)
{
	char item[SIZE];
	if (isEmptyQ(&q))
		printf("\nNobody is waiting!\n");
	else
	{
		printf("\nWaiting passengers:\n");
		while (!isEmptyQ(&q))
		{
			strcpy(item, remove(&q));
			printf("%s\n", item);
		}
	}
}