/*
 * Copyright (C) 2016 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2： 067
 * 	 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 *   数值为0或者字符串不是一个合法的数值则返回0
 *
 */
#include <stdio.h>

int err_status;

int str_to_int(const char *str)
{
	int i = 0;
	int value = 0, negative = 0;

	if (!str || *str == '\0') {
		err_status = -2;	// invald
		return 0;
	}

	switch (str[i]) {
	case '+':
		i++;
		break;
	case '-':
		i++;
		negative = 1;	// 负数
		break;
	default:
		break;
	}

	while(str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			err_status = -1;	// Invalid string
			return 0;
		}

		//printf("str[%d] = %c\n", i, str[i]);
		value = value * 10 + (str[i] - '0');
		i++;
	}

	return negative ? -value: value;
}

int main(int argc, char *argv[])
{
	int ret;

	ret = str_to_int(argv[1]);
	printf("%s = %d, err = %d\n", argv[1], ret, err_status);
	return 0;
}
