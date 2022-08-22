// A C++ Program to generate test cases for
// matrix filled with random numbers
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 3

// Define the range of the test data generated
#define MAX 100000

// Define the maximum rows in matrix
#define MAXROW 10

// Define the maximum columns in matrix
#define MAXCOL 10

int main()
{
	// Uncomment the below line to store
	// the test data in a file
	// freopen ("Test_Cases_Random_Matrix.in", "w", stdout);

	// For random values every time
	srand(time(NULL));

	for (int i=1; i<=RUN; i++)
	{
		// Number of rows and columns
		int row = 1 + rand() % MAXROW;
		int col = 1 + rand() % MAXCOL;

		// First print the number of rows and columns
		printf("%d %d\n", row, col);

		// Then print the matrix
		for (int j=1; j<=row; j++)
		{
			for (int k=1; k<=col; k++)
				printf("%d ", rand() % MAX);
			printf("\n");
		}
		printf("\n");
	}

	// Uncomment the below line to store
	// the test data in a file
	// fclose(stdout);
	return(0);
}
