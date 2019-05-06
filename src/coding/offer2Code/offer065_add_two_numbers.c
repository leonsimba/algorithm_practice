/*
 * 剑指offer2：065
 *     写一个函数，求两个整数之和.
 *     要求在函数体内不得使用+、-、*、/, 四则运算符号。
 *
 */
#include <stdio.h>

int add_two_number(int num1, int num2)
{
	int sum, carry;

	do {
		sum = num1 ^ num2;	// 执行无进位的加法操作
		carry = (num1 & num2) << 1;	// 获取进位值

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);	// 进位值为0，则退出循环

	return sum;
}

void main(void)
{
	int num1 = 7, num2 = 19;
	int ret;

	ret = add_two_number(num1, num2);
	printf("%d + %d = %d\n", num1, num2, ret);

	return;
}
