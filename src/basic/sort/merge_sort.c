/*
 * merge_sort.c - merge sort
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: ZhiPing He
 *
 */

#include <limits.h>	/* for INT_MAX */
#include "algor.h"

/* merge(A, p, m, r):
 * 	n1 = m - p + 1
 * 	n2 = r - m
 *	for i = 1 to n1
 *		L[i] = A[p + i - 1]
 *	for j = 1 to n2
 *		R[i] = A[m + j]
 *	L[n1 + 1] = largest number	// smart idea
 *	R[n2 + 1] = largest number
 *	i = j = 1
 *	for k = p to r
 *		if L[i] <= R[j]
 *			A[k] = L[i++]
 *		else
 *			A[k] = R[j++]
 */
static void merge(int base[], int left, int middle, int right, int buf[])
{
	int i, j, k;
	int L_len = middle - left + 1;
	int R_len = right - middle;
	int *L_array = buf;
	int *R_array = buf + L_len + 1;

	/* copy base[left, middle] to L_array[] */
	for (i = 0; i < L_len; i++)
		L_array[i] = base[left+i];
	L_array[L_len] = INT_MAX;

	/* copy base[middle+1, right] to R_array[] */
	for (j = 0; j < R_len; j++)
		R_array[j] = base[middle + 1 + j];
	R_array[R_len] = INT_MAX;

	i = j = 0;
	/* merge L_array and R_array to base[left, right] */
	for (k = left; k <= right; k++) {
		if (L_array[i] <= R_array[j])
			base[k] = L_array[i++];
		else
			base[k] = R_array[j++];
	}
}

/* merge-sort(A, p, r):
 * 	//split A to two array A[p, m] and A[m+1, r]
 *	if p < r
 *		m = (p + r)/2
 *		merge-sort(A, p, m)
 *		merge-sort(A, m+1, r)
 *		merge(A, p, m, r)
 */
static void merge_sort(int base[], int left, int right)
{
	if (left >= right)
		return;

	int len = right - left + 1;
	int middle = (right + left) / 2;
	int buf[len + 2]; // 2 items used to store INT_MAX

	merge_sort(base, left, middle);
	merge_sort(base, middle+1, right);
	merge(base, left, middle, right, buf);
}

int main()
{
	int left = 0, len;
	int base[] = {7, 1, 4, 9, 6, 20, 2, 18};

	len = sizeof(base)/sizeof(int);
	print_array(base, len);

	/* right index of array =  length - 1 */
	merge_sort(base, left, len - 1);
	print_array(base, len);
	return 0;
}
