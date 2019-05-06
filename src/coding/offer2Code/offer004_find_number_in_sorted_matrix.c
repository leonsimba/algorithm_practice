/*
 * Copyright (C) 2016 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：004
 *    一个二维数组，每行按照从左到右递增排序，每列都按照从上到下递增排序.
 *    输入一这样的二维数组和一个整数，判断数组中是否含有该整数。
 *
 *    {1, 2, 8,  9},
 * 	  {2, 4, 9,  12},
 * 	  {4, 7, 10, 13},
 * 	  {6, 8, 11, 15}
 *
 */
#include <stdio.h>

static int array[][4] = {
	{1, 2, 8,  9},
	{2, 4, 9,  12},
	{4, 7, 10, 13},
	{6, 8, 11, 15}
};

//int find_item(int ar[][4], int num, int *x, int *y)
//int find_item(int ar[][4], int num, int *x, int *y)
int find_item(int (*ar)[4], int num, int *x, int *y)
{
	int i, j;
	int ret = 0;

	for (i = 0, j = 3; i <= 3 && j >= 0;) {

		if (ar[i][j] == num) {
			*x = i;
			*y = j;
			ret = 1;	// find it
			break;
		} else if (ar[i][j] > num) {
			j--;
		} else {
			i++;
		}
	}

	return ret;
}


int main(int argc, char *argv[])
{
	int ret;
	int i, j;
	int key = atoi(argv[1]);

	ret = find_item(array, 1, &i, &j);
	if (ret) {
		printf("i = %d, j = %d\n", i, j);
	}

	return;
}
