/*
 * 剑指Offer2：066
 *    给定一个数组A[0, 1, …, n1],  不能用除法，请构建一个数组B[0, 1, …, n-1]，
 *    其中, B中的元素
 *    B[0] =A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]
 *    B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。
 *
 */
#include "algor.h"

double * construct_array(double *array_A , int len)
{
	double * left_array, *right_array;
	double * array_B;
	int i;

	left_array= (double *) malloc(sizeof(double) * len);
	if (!left_array)
		return NULL;

	right_array= (double *) malloc(sizeof(double) * len);
	if (!right_array) {
		free(left_array);
		return NULL;
	}

	array_B= (double *) malloc(sizeof(double) * len);
	if (!array_B) {
		free(left_array);
		free(right_array);
		return NULL;
	}

	left_array[0] = 1;
	for (i = 1; i < len; i++) {
		left_array[i] = left_array[i-1] * array_A[i-1];
	}

	right_array[len-1] = 1;
	for (i = len-2; i >= 0; i--) {
		right_array[i] = right_array[i+1] * array_A[i+1];
	}

	for (i = 0; i < len; i++) {
		array_B[i] = left_array[i] * right_array[i];
	}

	return array_B;
}

int main()
{
	double array_A[]={1, 2, 3, 4, 5};
	double *array_B;
	int i, len = sizeof(array_A)/sizeof(double);

	array_B = construct_array(array_A, len);
	if (!array_B)
		return -1;

	for (i = 0; i < len; i++ )
		printf("B[%d] = %lf \n", i, array_B[i]);
	printf("\n");

	return 0;
}
