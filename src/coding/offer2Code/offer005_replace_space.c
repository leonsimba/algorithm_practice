/*
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：005
 *    实现一个函数，把字符串中的每个空格替换成”%20”。
 *    例如：输入“We are happy”，则输出“We%20are%20happy”
 *
 */
#include "algor.h"

// return a new string
char * replace_whitespace(char *in)
{
	int number = 0, count = 0;
	int i = 0, len;
	char * out;

	while (in[i++] != '\0') {
		if (in[i] == ' ') {
			count++;	// white space number
		}
	}

	len  = i + count * 2;
	out = (char *) malloc(len);
	if (!out)
		return NULL;

	out[len--] = '\0';
	while (--i >= 0) {
		if (in[i] == ' ') {
			out[len--] = '0';
			out[len--] = '2';
			out[len--] = '%';
		} else {
			out[len--] = in[i];
		}
	}

	return out;
}

void main()
{
	char str[] = "We are happy";
	char *res;

	res = replace_whitespace(str);
	if (res) {
		printf("%s\n", res);
	}

	return;
}
