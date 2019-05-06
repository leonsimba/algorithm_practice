/*
 * Copyright (C) 2016 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：058
 *    将一个句子进行反转，并且句子中的单词也需要放反转。
 *    例如, “I am a studen." 反转后为 “student. a am "
 *
 */
#include "algor.h"

void reverse(char *str, int len)
{
	int left, right;
	char tmp;

	left = 0;
	right = len - 1;

	for (left = 0; left < right; left++, right--) {
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
	}
}

char *reverse_sentence(char *str, int len)
{
	char *start, *end;

	if (!str || len < 2)
		return str;

	// First, reverse the whole sentence
	reverse(str, len);

	// Then, reverse every word in the sentence
	start = end = str;
	while (*end != '\0') {
		// meet a whitespace
		if (*end == ' ') {
			reverse(start, end - start);
			start = end + 1;
		} else if (*(end + 1) == '\0') {
			reverse(start, end - start + 1);
		}
		end++;
	}

	return str;
}

void main(void)
{
	char str1[] = "hello world";
	char str2[] = "  hi world  ";
	char str3[] = "hello nice to see you";
	char *ret;

	printf("string  : %s\n", str1);
	ret = reverse_sentence(str1, strlen(str1));
	printf("reverse : %s\n", ret);

#if 1
	printf("string  : %s\n", str2);
	ret = reverse_sentence(str2, strlen(str2));
	printf("reverse : %s\n", ret);

	printf("string  : %s\n", str3);
	ret = reverse_sentence(str3, strlen(str3));
	printf("reverse : %s\n", ret);
#endif

	return;
}
