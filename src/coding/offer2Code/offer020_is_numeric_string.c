/*
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指offer2: 020
 *    请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 *    例如，字符串"+100"、"5e2"、"-123"、"3.1416"和"-1E-16"都表示数值。
 *    例如，字符串"12e"、"1a3.14"、"1.2.3"、"+-5"和"12e+4.3"都不是表示数值。
 *
 */
#include <stdio.h>

int check_number(char *start, const char *end, int flag)
{
	int first = 1;
	char *p = start;

	while (p && p != end && (*p != '\0')) {
		switch (*p) {
		case '+':
		case '-':
			if (flag)  // 小数部分的不能包含'+'或‘-’
				return -1;

			if (first) // 整数和指数部分，只有第1个字符才可以是'+'或‘-’
				first = 0;
			else
				return -1;
			break;
		default:
			first = 0;
			if ( *p < '0' || *p > '9')
				return -1;
		}
		p++;
	}

	return 0;
}

int is_numeric_string(char *str)
{
	char *p_i = NULL, *p_d = NULL, *p_e = NULL;
	int c_dot = 0, c_e = 0;
	int ret = -1;

	if (!str)
		return ret;

	if (*str != '.')
		p_i = str;

	while (*str != '\0') {
		switch (*str) {
		case '.':				// 获取小数部分的起始位置
			if (++c_dot > 1)
				return -1;
			p_d = str;
			break;
		case 'e':				// 获取指数部分的起始位置
		case 'E':
			if (++c_e > 1)
				return -1;
			p_e = str;
			break;
		default:
			break;
		}
		str++;
	}

	// 检查整数部分
	ret = check_number(p_i, p_d ? p_d : p_e, 0);
	if (ret)
		return ret;

	// 检查小数部分
	ret = check_number(p_d + 1, p_e, 1);
	if (ret)
		return ret;

	// 检查指数部分
	ret = check_number(p_e + 1, NULL, 0);
	if (ret)
		return ret;

	return 0;
}

void main()
{
	char *str[] = {"+100", "5e2", "-123", "3.1416", "-1E-16",
					"12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"};
	int len = sizeof(str)/sizeof(char *);
	int i, ret;

	for (i = 0; i < len; i++) {
		ret = is_numeric_string(str[i]);
		printf("%s : %d\n", str[i], ret);
	}

	return;
}
