#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(FILE* b_outp, char direction, int n) { //direction as T-Top B-Bottom and C-Current

	switch (direction) {
		// if the direction is T-Top
	case 'T':
	case 't':
		fseek(b_outp, (n - 1) * sizeof(int), SEEK_SET);
		break;
		// if the direction is C-Current
	case 'C':
	case 'c':
		fseek(b_outp, (n - 1) * sizeof(int), SEEK_CUR);
		break;
		// if the direction is B-Bottom
	case 'B':
	case 'b':
		fseek(b_outp, (-n) * sizeof(int), SEEK_END);
	}
}
