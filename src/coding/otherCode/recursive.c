#include <stdio.h>

int count = 0;

void func1(int s, int n)
{
	if (s == n) {
		count++;
		return;
	} else if (s > n) {
		return;
	}

	func1(s+1, n);
	func1(s+2, n);
}

void func2(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;

	return func2(n-1) + func2(n-2);
}

void main()
{
	func1(0, 5);
	printf("count = %d\n", count);

	count = 0;
	func2(5);
	printf("count = %d\n", count);
}
