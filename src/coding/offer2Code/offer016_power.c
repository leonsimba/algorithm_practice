/*
 * Copyright (C) 2016 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：016
 *    实现函数double Power(double base, int exponent)，求base的exponent次方,
 *    无需考虑大数问题。
 *
 *    这也是考察基础库函数power()的实现题目, 考察考虑问题的全面性.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

unsigned int invalid_input = 0;

int equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return 1;
	else
		return 0;
}


double calculate_power(double base, unsigned int power)
{
	if (power == 0)
		return 1;

	if (power == 1)
		return base;

	if (power % 2) {
		return base * calculate_power(base, power/2) * calculate_power(base, power/2);
	} else {
		return calculate_power(base, power/2) * calculate_power(base, power/2);
	}
}

double power(double base, int exponent)
{
	double result;
	unsigned int power = (unsigned int) exponent;

	if (equal(base, 0.0) && exponent < 0) {
		invalid_input = 1;
		return 0.0;
	}

	// 指数为负数时，先转换成整数
	if (exponent < 0)
		power = (unsigned int) (-exponent);

	result = calculate_power(base, power);

	// 指数为负数时，需要对结果求倒数
	if (exponent < 0)
		result = (1.0/result);

	return result;
}

void test(double base, int exponent)
{
	double result;

	invalid_input = 0;
	result = power(base, exponent);

	printf("base = %lf, exponent = %d, result = %lf, invalid = %d\n",
			base, exponent, result, invalid_input);

}

void main(void)
{
	double base, result;
	int exponent;

	test(0.0, -2);
	test(-2, 2);
	test(2.2, 4);
	test(2.2, 5);

}
