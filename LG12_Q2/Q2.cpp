#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
	char make[20];
	char model[20]; 
	int year;
	double price; 
	char color[15];
}car_t;

int main(void)
{
	FILE* inp_b;
	inp_b = fopen("cars.bin", "rb");
	if (inp_b == NULL)
		printf("cannot open the file.");
	else {
		int n;
		car_t *arr;
		fseek(inp_b, sizeof(car_t), SEEK_END);
		n = ftell(inp_b)/sizeof(car_t);
		rewind(inp_b);
		printf("There are %d cars in the file.\n", n-1);
		arr = (car_t*)malloc(n*sizeof(car_t));

		int num;
		fread(arr, sizeof(car_t) * n, num, inp_b);

		srand(time(NULL));
		num = rand() % (n-1) + 1; //at least 1 car will be displayed

		printf("%d cars will be displayed\n", num);
		printf("Make          Model        Year        Price        Color\n");
		printf("----------------------------------------------------------\n");
		for(int i = 0; i< num; i++)

		printf("%-10s %8s       %5d      $%5.2f  %10s\n",(arr + i)->make, (arr + i)->model, (arr + i)->year, (arr + i)->price, (arr + i)->color);
		fclose(inp_b);
	}

	return 0;
}
