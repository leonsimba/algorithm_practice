/*
 * ��ָOffer2��064
 *     ��1+2+��+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
 *     �ȹؼ��ּ������ж���䣨A?B:C����
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
	 * �����߼�������:
	 * 1) ���ֵΪ�棬�����η�֮�󣬽��Ϊ 1;
	 * 2) ���ֵΪ�٣������η�֮�󣬽��Ϊ 0;
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
