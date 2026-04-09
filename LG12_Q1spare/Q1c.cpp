
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createBinaryFile()
{
	FILE* outp_b;
	outp_b = fopen("numbers.bin", "wb");
	int* arr;
	arr = (int*)malloc(250 * sizeof(int));
	int n;
	srand(time(NULL));
	for (int i = 0; i < 250; i++)
	{
		n = rand() % 5000 + 1;
		*(arr + i) = n;
	}
	fwrite(arr, sizeof(int), 250, outp_b);

	fclose(outp_b);
}

int main(void)
{
	FILE* inp_b;
	createBinaryFile();

	inp_b = fopen("numbers.bin", "rb");
	if (inp_b == NULL)
		printf("Cannot open the file.");
	else {
		int n;
		int search;
		printf("Please enter the order of the item to be read: ");
		scanf("%d", &n);

		fseek(inp_b, sizeof(int) * (n - 1), SEEK_SET);
		fread(&search, sizeof(int), 1, inp_b);
		printf("%d. %d\n", n, search);
		fclose(inp_b);
	}
	return 0;
}