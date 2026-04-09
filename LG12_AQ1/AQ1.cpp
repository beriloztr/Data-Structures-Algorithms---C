#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[25];
	int stock, arrive;
}info_t;

int rBinarySearch(int top, int bottom, char item[], info_t *mal)
{
	int mid = (top + bottom) / 2;
	printf("top: %d, bottom: %d, middle: %d; %s\n", top, bottom, mid, (mal+ mid)->name);
	if(top > bottom){
		if (strcmp(item, (mal + mid)->name) < 0)
			rBinarySearch(mid - 1, bottom, item, mal);
		else if (strcmp(item, (mal + mid)->name) > 0)
			rBinarySearch(top, mid + 1, item, mal);
		else
			return (mid);
	}
	else
		return -1;
}

int main(void)
{
	FILE* inp;
	inp = fopen("items.bin", "rb");
	if (inp == NULL)
		printf("Cannot open the file.");
	else {
		int n;
		fseek(inp, 0, SEEK_END);
		n =ftell(inp)/sizeof(info_t);
		rewind(inp);
		info_t* mal;
		mal = (info_t*)malloc(sizeof(info_t)*n);
		fread(mal, sizeof(info_t), n, inp);
		printf("There are %d items in the list\n", n);

		char item[25];
		printf("Enter an item to search: ");
		scanf("%[^\n]", item);

		int ind = rBinarySearch(n-2, 0, item, mal);
		if (ind == -1)
			printf("%s could not be found!\n",item);
		else
			printf("%s found with %d stocks and %d stocks will arrive\n", item, (mal + ind)->stock, (mal + ind)->arrive);
		fclose(inp);
	}
	return 0;
}