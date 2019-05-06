/*
 * bubble.c - bubble sort (O(n2))
 *
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

void bubble_sort(int a[], unsigned int a_len)
{
	int i, j;

	for (i = a_len; i > 0; i--) {
		int flag = 0;
		for (j = 1; j < i; j++) {
			if (a[j] < a[j-1]) {
				exchange(a, j, j-1);
				flag = 1; /* exchange happened*/
			}
		}
		/* If no exchange happened, means the array is
                 * already ordered.
                 */
		if (flag == 0)
			break;
	}
}

int main()
{
	int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	unsigned int array_length;

	array_length = sizeof(a)/sizeof(int);
	print_array(a, array_length);

	bubble_sort(a, array_length);
	print_array(a, array_length);

	return 0;
}
