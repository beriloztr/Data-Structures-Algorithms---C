#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define SIZE 100

/*
Author: Beril Ozturk
Q3: Write a C program that reads IDs and game scores of several bowling teams from the file 
“bowling.txt”; finds and displays the average of each game and the average of each team using
the following functions:

* readFromFile: takes a file pointer, a one-dim array to keep the team Ids and a two-dimensional array to keep the game scores as parameter.
The function reads the team IDs into the one-dim array and 4 game scores of several bowling teams into the two-dim array from the specified file. 

* findTeamAvg: takes the two-dim scores array and the number of team as input parameters, finds the average of each team and stores the averages 
into a one-dim array.

* findGameAvg takes the two-dim scores array and the number of team as input parameters, finds the average of each game and stores the averages 
into a one-dim array.

* displayGameAvg: takes the one-dim array which keeps the game averages as input parameter and displays the averages of all games on the screen.

The function also returns the number of teams.
Project Name: LG01_Q3
File Name: Q3.cpp
*/


/*
Another way to read
int readFromFile(FILE* inp, int ID[], int score[][4])
{
	int t = 0;

	while (fscanf(inp, "%d %d %d %d %d", &ID[t], &score[t][0], &score[t][1], &score[t][2], &score[t][3]) != EOF)
		t++;

	return(t);
}
*/


int readFromFile(FILE* inp, int ID[], int score[][4])
{
	int t = 0;

	while (fscanf(inp, "%d ", &ID[t]) != EOF)
	{
		for (int k = 0; k < 4;k++)
		{
			fscanf(inp, "%d ", &score[t][k]);
		}
		t++;

	}
		

	return(t);
}

void findTeamAvg(int score[][4], int t, double teamavg[], int ID[])
{
	printf("Team Number\tAverage\n");
	printf("**********\t********\n");

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			teamavg[i] += score[i][j];

		}
		printf("%d\t\t", ID[i]);
		printf("%.2f\n", teamavg[i] / 4);
	}

}

void findGameAvg(int score[][4], int t, double gameavg[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < t; j++)
		{
			gameavg[i] += score[j][i];

		}
		gameavg[i] /= t;

	}

}

void displayGameAvg(double gameavg[], int t)
{
	printf("Game Number\tAverage\n");
	printf("**********\t********\n");

	for (int i = 0; i < 4; i++)
	{
		printf("%d\t\t%.1f\n", i + 1, gameavg[i]);
	}

}

int main(void)
{
	int score[SIZE][4], t, ID[SIZE];
	double teamavg[SIZE] = {}, gameavg[SIZE] = {};
	FILE* inp;
	inp = fopen("bowling.txt", "r");

	if (inp == NULL)
		printf("cannot open the file.");

	else
	{
		t = readFromFile(inp, ID, score);
		findTeamAvg(score, t, teamavg, ID);
		printf("\n");
		findGameAvg(score, t, gameavg);
		displayGameAvg(gameavg, t);


	}
	return 0;
}
