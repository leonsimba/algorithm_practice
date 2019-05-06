/*
 * shell_sort.c - shell sort
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

static void shell_sort(int a[], unsigned int len)
{
	int increment;
	int i, j;

	for (increment = len/2; increment > 0; increment /= 2) {
		/* foreach split array, use insert sort */
		for (i = increment; i < len; i++) {
			int key = a[i];
			int j = i - increment;
			while (j >= 0 && a[j] > key) {
				a[j+increment] = a[j];
				j = j - increment;
			}
			a[j + increment] = key;
		}
	}
}

int main()
{
	int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1, 10};
	unsigned int array_length;

	array_length = sizeof(a)/sizeof(int);
	print_array(a, array_length);

	shell_sort(a, array_length);
	print_array(a, array_length);

	return 0;
}
