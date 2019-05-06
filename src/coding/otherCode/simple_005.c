#include <stdio.h>

void sort_array(int *a1, int n1,  int *a2, int n2, int len)
{
	int i = n1 - 1, j = n2 - 1;

	while (i >= 0 && j >= 0) {
		if (a1[i] >= a2[j]) {
			a1[--len] = a1[i--];
		} else {
			a1[--len] = a2[j--];
		}
	}

	while (j >= 0) {
		a1[--len] = a2[j--];
	}
}

void main()
{
	int a1[7]={1, 2, 4, 9};
	//int a1[7]={8, 9, 11, 12};
	int a2[]={3, 5, 7};
	int len1, len2, len;
	int i;

	sort_array(a1, 4, a2, 3, 7);	

	for (i = 0; i < 7; i++) {
		printf("%d ", a1[i]);
	}
	printf("\n");

	return;
}
