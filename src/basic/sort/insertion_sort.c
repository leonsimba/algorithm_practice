/*
 * insertion_sort.c - insertion sort
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

/* insertion-sort(A):
 * 	for j = 2 to A.length
 *		key = A[j]
 *		//Insert A[j] into the sorted sequence A[1 .. j-1]
 *		i = j - 1
 *		while i > 0 && A[i] > key
 *			A[i+1] = A[i]
 *			i = i - 1
 *		A[i+1] = key
 */
static void insertion_sort(int a[], int len)
{
	int i, j;
	int key;

	for (j = 1; j < len; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

int main()
{
	int a[] = {5, 2, 4, 6, 1, 3};
	unsigned int array_len;

	array_len = sizeof(a) / sizeof(int);
	print_array(a, array_len);

	insertion_sort(a, array_len);
	print_array(a, array_len);

	return 0;
}
