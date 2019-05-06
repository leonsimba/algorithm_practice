/*
 * 剑指Offer2：003
 *    有一个长度为n的数组, 数组中的元素的值范围为[0, n-1]。
 *    数组中有重复数字，但不知道有几个数字是重复的,也不知道每个数字重复几次.
 *    请找出数组中任意一个重复的数字。
 *    例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，则第一个重复的数字为2
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static int max = 10;

// method_v1
unsigned int find_first_duplicate_number_v1(unsigned int *array, int len)
{
	unsigned int * hash_table;
	int i;

	hash_table = (int *) malloc(max * sizeof(int));
	if (!hash_table) {
		return -ENOMEM;
	}
	memset(hash_table, 0, max * sizeof(int));

	for (i = 0; i < len; i++) {
		unsigned int x = array[i];

		if (hash_table[x])	// find it
			return x;

		hash_table[x] += 1;
	}

	return -1;	// not find a duplicate number
}

// method_v2
unsigned int find_first_duplicate_number_v2(unsigned int *array, int len)
{
	int i=0, tmp;

	while (i < len) {

		if (array[i] == i) {
			i++;
			continue;
		}

		if (array[i] == array[array[i]]) {	// find it
			return array[i];
		} else {
			tmp = array[array[i]];
			array[array[i]] = array[i];
			array[i] = tmp;
		}
	}

	return -1; // not find a duplicate number
}

int main()
{
	int array[]={2, 3, 1, 0, 2, 5, 3};
	int len = sizeof(array)/sizeof(int);
	int number;

	number = find_first_duplicate_number_v1(array, len);
	printf("The first duplicate number is %d\n", number);

	number = find_first_duplicate_number_v2(array, len);
	printf("The first duplicate number is %d\n", number);

	return 0;
}
