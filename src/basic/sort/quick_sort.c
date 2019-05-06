/*
 * quick_sort.c - quick sort
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: ZhiPing He
 *
 */
#include "algor.h"

/* partition(A, p , r)
 *	x = A[r]
 *	i = p - 1
 *	for j = p to r-1
 *		if A[j] <= x
 *			i = i+1
 *			exchange A[i] with A[j]
 *	exchange A[i+1] with A[r]
 *	return i + 1
 */
static int partition(int array[], int left, int right)
{
	int x;
	int q, i, j;

	x = array[right];
	i = left - 1;
	for (j = left; j < right; j++) {
		if (array[j] <= x) {
			i = i + 1;
			exchange(array, i, j);
		}
	}
	// exchange array[right] with array[p]
	q = i + 1;
	exchange(array, q, right);
	return q;
}

/* quick_sort(A, p , r)
 *	if (p < r)
 *		q = partition(A, p , r)
 *		quick_sort(A, p, q - 1)
 *		quick_sort(A, q + 1, r)
 */
static void quick_sort(int array[], int left, int right)
{
	int q;

	if (left >= right)
		return;

	q = partition(array, left, right);
	quick_sort(array, left, q - 1);
	quick_sort(array, q + 1, right);
}

int main()
{
	int left = 0, len;
	int base[] = {7, 1, 4, 9, 6, 20, 2, 18};

	len = sizeof(base)/sizeof(int);
	print_array(base, len);

	/* right index of array =  length - 1 */
	quick_sort(base, left, len - 1);
	print_array(base, len);
	return 0;
}
