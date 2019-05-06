/*
 * counting_sort.c - counting sort ( O(n) )
 *
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: ZhiPing He
 *
 */

#include "algor.h"

static int get_max_number(int a[], int a_len)
{
	int i, max = a[0];

	for (i = 1; i < a_len; i++)
		max = a[i] > max ? a[i] : max;
	return max;
}

/*couting-sort(A, B, k)
 *	let C[0..k] be a new array
 *	for i= 0 to k
 *	    C[i] = 0
 * 	for j= 1 to A.length
 *	    C[A[j]] = C[A[j]] + 1
 * 	// C[i] now contains the number of elements equal to i.
 *	for i = 1 to k
 *	    C[i] = C[i] + C[i - 1]
 *	// C[i] now contains the number of elements less than or equal to i.
 *	for j = A.length downto 1
 *	    B[C[A[j]]] = A[j]
 *	    C[A[j]] = C[A[j]] - 1
 */
static void counting_sort(int a[], int b[], int a_len, int k)
{
	int i;
	int c[k+1];

	memset(c, 0, sizeof(c));
	for (i = 0; i < a_len; i++)
		c[a[i]] = c[a[i]] + 1;
	// C[i] now contains the number of elements equal to i.

	for (i = 1; i <= k; i++)
		c[i] = c[i] + c[i-1];
	// C[i] now contains the number of elements less than or equal to i.

	for (i = a_len - 1; i >= 0; i--) {
		/* put the a[i] into the right position.
                 * minus 1, because b[] start at index 0.
                 */
		b[c[a[i]] - 1] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}
}

int main()
{
	int k;
	int a[] = {16, 0, 10, 14, 7, 7, 3, 2, 8, 1, 1};
	int a_len = sizeof(a)/sizeof(int);
	int b[a_len];

	print_array(a, a_len);
	k = get_max_number(a, a_len);
	counting_sort(a, b, a_len, k);
	print_array(b, a_len);

	return 0;
}
