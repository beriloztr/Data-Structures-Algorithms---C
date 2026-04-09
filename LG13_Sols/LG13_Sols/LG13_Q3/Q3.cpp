/* LG13_Q3 -> Recursive Binary Search and Bubble Sort */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define SIZE 20
#define MAXCNT 50

typedef struct
{
	char username[SIZE];
	char name[SIZE];
	char surname[SIZE];
	char phone[SIZE];
}user_t;

int readFromFile(FILE *inp, user_t userList[]);
void display(user_t userList[], int noOfUsers);
void swap(user_t *x, user_t *y);
void recBubbleSort(user_t userList[], int n);
int recBinarySearch(user_t userList[], int top, int bottom, char srchTitle[]);

int main(void)
{
	FILE *inp = fopen("userinfo.txt", "r");

	if (inp == NULL)
		printf("Error\n");
	else
	{
		user_t userList[MAXCNT];
		int indx;
		char srchTitle[SIZE];

		//read the information from the file into the structure array
		int noOfUsers = readFromFile(inp, userList);
		fclose(inp);

		//sort the list according to the username in ASC order
		recBubbleSort(userList, noOfUsers);

		printf("There are %d users in the list\n\n", noOfUsers);
		//display the sorted list 
		display(userList, noOfUsers);

		//read a name to search until "END" is given
		printf("\nEnter the username (END for exit): ");
		scanf("%s", srchTitle);

		while (strcmp(srchTitle, "END") != 0)
		{
			//search the list for the specified name
			indx = recBinarySearch(userList, 0, noOfUsers, srchTitle);

			if (indx != -1)
				printf("%-20s %-20s %-20s %-20s\n", userList[indx].username, userList[indx].name, userList[indx].surname, userList[indx].phone);
			else
				printf("NOT FOUND\n");

			printf("\nEnter the username (END for exit): ");
			scanf("%s", srchTitle);
		}
	}
	return 0;
}

int readFromFile(FILE *inp, user_t userList[])
{
	int i, status;
	i = 0;

	while (fscanf(inp, "%s %s %s %s", userList[i].username, userList[i].name, userList[i].surname, userList[i].phone) != EOF)
		i++;

	return i;
}

void display(user_t userList[], int noOfQuestion)
{
	printf("Username          Name          Surname           Phone \n");
	printf("***************   ************  ************* *************\n");

	for (int i = 0; i < noOfQuestion; i++)
		printf("%-16s  %-13s %-13s %-13s\n", userList[i].username, userList[i].name, userList[i].surname, userList[i].phone);
}

void swap(user_t *x, user_t *y)
{
	user_t temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void recBubbleSort(user_t userList[], int n)
{
	int k;
	int sorted = 1;
	for (k = 0; k < n - 1; k++)
	{
		if (strcmp(userList[k].username, userList[k + 1].username) > 0)
		{
			swap(&userList[k], &userList[k + 1]);
			sorted = 0;
		}
	}

	/* if the array is not sorted at the end of a pass,
	make another pass */
	if (!sorted)
		recBubbleSort(userList, n - 1);
}

//search list recursively for a name using binary search algorithm
int recBinarySearch(user_t pList[], int top, int bottom, char srchTitle[])
{
	int middle;

	if (top > bottom)
		return -1;
	else
	{
		middle = (top + bottom) / 2;

		if (strcmp(pList[middle].username, srchTitle) == 0)
			return middle;
		else
			if (strcmp(pList[middle].username, srchTitle) > 0)
				return(recBinarySearch(pList, top, middle - 1, srchTitle));
			else
				return(recBinarySearch(pList, middle + 1, bottom, srchTitle));
	}
}