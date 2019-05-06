/*
 * Some common Operation
 */
#include "algor.h"

void print_array(int *array, int len)
{
	int i;

	for(i = 0; i < len; i++)
		printf("a[%d]=%d ", i, array[i]);
	printf("\n");
}

void exchange(int *array, int a, int b)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
}
