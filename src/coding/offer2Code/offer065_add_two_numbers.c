/*
 * ��ָoffer2��065
 *     дһ������������������֮��.
 *     Ҫ���ں������ڲ���ʹ��+��-��*��/, ����������š�
 *
 */
#include <stdio.h>

int add_two_number(int num1, int num2)
{
	int sum, carry;

	do {
		sum = num1 ^ num2;	// ִ���޽�λ�ļӷ�����
		carry = (num1 & num2) << 1;	// ��ȡ��λֵ

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);	// ��λֵΪ0�����˳�ѭ��

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
