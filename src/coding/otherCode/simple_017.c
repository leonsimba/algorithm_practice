/*
 * 题目：获取一个二进制高位连续1的个数，比如1101，则结果为2。
 *
 */
#include <stdio.h>

#define MASK	0x80000000	// 32 bits

int number_of_leading_one(int i)
{
	int count = 0;

	while (i) {
		if (i & MASK)
			count++;
		else
			break;
		i = i << 1;
	}

	return count;
}

void main(int argc, char *argv[])
{
	int count;

	int x = 0xf0100000;

	count = number_of_leading_one(x);
	printf("0x%x, count = %d\n", x, count);

	x = 0x00100000;
	count = number_of_leading_one(x);
	printf("0x%x, count = %d\n", x, count);

	return;	
}
