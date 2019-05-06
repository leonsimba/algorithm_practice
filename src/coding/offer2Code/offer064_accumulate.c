/*
 * 剑指Offer2：064
 *     求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
 *     等关键字及条件判断语句（A?B:C）。
 */
#include <stdio.h>

typedef unsigned int (*func)(unsigned int);

unsigned int terminator(unsigned int n)
{
	return 0;
}

unsigned int sum(unsigned int n)
{
	static func f[2]={terminator, sum};

	/*
	 * 两次逻辑非运算:
	 * 1) 如果值为真，则两次非之后，结果为 1;
	 * 2) 如果值为假，则两次非之后，结果为 0;
	 */
	return n + f[!!n](n - 1);
}

void main(void)
{
	unsigned int n, ret;

	n = 0;
	ret = sum(n);
	printf("n = %d, sum = %d\n", n, ret);

	n = 1;
	ret = sum(n);
	printf("n = %d, sum = %d\n", n, ret);

	n = 10;
	ret = sum(n);
	printf("n = %d, sum = %d\n", n, ret);

	return;
}
