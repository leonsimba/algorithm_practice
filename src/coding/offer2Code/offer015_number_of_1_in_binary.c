/*
 * Copyright (C) 2016 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：015
 *    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 *
 */
#include <stdio.h>

int counts_v3(int i)
{
	int count = 0;

	while(i) {
		i = (i - 1) & i;
		count++;
	}

	return count;
}

int counts_v2(int i)
{
	int count = 0;
	unsigned int flag = 1;

	while (flag) {
		if (i & flag)
			count++;
		flag = flag << 1;
	}

	return count;

}
int counts_v1(int i)
{
	int count = 0;

	if (i == 0) {
		return count;
	}

	if (i > 0) {
		while (i > 0) {
			count += i % 2 ? 1 : 0;
			i = i >> 1;
		}
	} else {
		i = ~i;
		while (i > 0) {
			count += i % 2 ? 1 : 0;
			i = i >> 1;
		}
		count = 32 - count;
	}

	return count;
}

void main(int argc, char *argv[])
{
	int n;
	int i = atoi(argv[1]);

	n = counts_v1(i);
	printf("%d, count = %d\n", i, n);

	n = counts_v2(i);
	printf("%d, count = %d\n", i, n);

	n = counts_v3(i);
	printf("%d, count = %d\n", i, n);
}
