#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		car_t* arr;
		fseek(inp_b, sizeof(car_t), SEEK_END);
		n = ftell(inp_b) / sizeof(car_t);
		rewind(inp_b);
		printf("There are %d cars in the file.\n", n - 1);
		arr = (car_t*)malloc(n * sizeof(car_t));

		int j = 0, count = 0;
		FILE* outp_b;
		outp_b = fopen("output.bin", "wb");
		while (!feof(inp_b))
		{
			fread(arr + j, sizeof(car_t), 1, inp_b);
			if (strcmp((arr + j)->color, "black") == 0)
			{
				fwrite((arr + j), sizeof(car_t) , 1, outp_b);
				count++;
			}
			j++;
		}
		fclose(outp_b);

		printf("BINARY FILE CONTENT\n*******************\n");
		printf("Make          Model        Year        Price        Color\n");
		printf("----------------------------------------------------------\n");
		car_t x;
		FILE* outp;
		outp = fopen("output.bin", "rb");
		for (int i = 0; i < count; i++)
		{
			fread(&x, sizeof(car_t), 1, outp);
			printf("%-10s %8s       %5d      $%5.2f  %10s\n", x.make, x.model, x.year, x.price, x.color);
		}

		fclose(inp_b);
	}
	return 0;
}
