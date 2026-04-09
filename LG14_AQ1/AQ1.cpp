#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_int.h"
#define SIZE 50
int menu()
{
	int choice;
	printf("MENU\n***********************\n");
	printf("1) Count Stack\n");
	printf("2) Remove Maximum Element\n");
	printf("3) Send Nth To End\n");
	printf("4) Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	//validation missing
	return choice;
}
int main(void)
{
	int nb;
	stack_t S;
	initializeS(&S);
	printf("Enter a number: ");
	scanf("%d", &nb);
	while (nb > 0) {
		push(&S, nb);
		printf("Enter a number: ");
		scanf("%d", &nb);
	}
	int choice = menu();
	int size = CountStack(S);

	while (choice != 4)
	{
		switch (choice) {
		case 1:
			DisplayStack(S);
			printf("Number of elements in the stack: %d\n", size);
			break;
		case 2:
			RemMaxStack(&S);
			size -= 1;
			DisplayStack(S);
			break;
		case 3:
			int n;
			DisplayStack(S);
			printf("Enter N: ");
			scanf("%d", &n);
			SendNthToEnd(&S, n);
			DisplayStack(S);
			break;
		}
		choice = menu();
	}


	return 0;
}