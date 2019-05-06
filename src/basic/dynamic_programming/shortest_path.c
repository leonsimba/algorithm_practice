#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N  4
//#define min(a, b)  ((a - b) > 0 ? b : a)
#define min(a, b)  ((a) < (b) ? (a) : (b))

int min = 1000;
int path[N][N] = {
	{1, 3, 5, 9},
	{2, 1, 3, 4},
	{5, 2, 6, 7},
	{6, 8, 4, 3}
};

void shortest_distance(int i, int j, int distance, int n)
{
	if (i == n && j == n) {
		if (distance < min)
			min = distance;
		return;
	}

	if (i < n) {
		shortest_distance(i+1, j, distance + path[i+1][j], n);
	}

	if (j < n) {
		shortest_distance(i, j+1, distance + path[i][j+1], n);
	}
}

// solution 2:
//  F[0][0] = 1
//  i = 0 && j > 0, F[0][j] = F[0][j-1] + path[0][j]
//  i > 0 && j = 0, F[i][0] = F[i-1][0] + path[i][0]
//  i > 0 && j > 0, F[i][j] = min (F[i-1][j]) , F[i][j-1]) + path[i][j]

int shortest_distance2(int i, int j, int n)
{
	int F[N][N];

	memset(F, 0, N * N * sizeof(int));

	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {
			if (i == 0 &&  j == 0) {
				F[i][j] = 1;
			} else if (i == 0) {
				F[i][j] = F[i][j-1] + path[i][j];
#ifdef DEBUG
				printf("F[%d][%d] = %d", i, j, F[i][j]);
#endif
			} else if (j == 0) {
				F[i][j] = F[i-1][j] + path[i][j];
#ifdef DEBUG
				printf("F[%d][%d] = %d", i, j, F[i][j]);
#endif
			} else {
				F[i][j] = min(F[i-1][j], F[i][j-1]) + path[i][j];
#ifdef DEBUG
				printf("F[%d][%d] = %d", i, j, F[i][j]);
#endif
			}
		}
	}

#ifdef DEBUG
	printf("F[%d][%d] = %d\n", i-1, j-1, F[i-1][j-1]);
#endif
	return F[i-1][j-1];
}

void main()
{
	int ret;

	shortest_distance(0, 0, path[0][0], N-1);
	printf("<0, 0> --> <3, 3>, minest distance is %d\n", min);

	ret = shortest_distance2(0, 0, N);
	printf("<0, 0> --> <3, 3>, minest distance is %d\n", ret);
}
