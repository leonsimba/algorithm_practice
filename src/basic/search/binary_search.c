/*
 *  Binary Search， 二分查找
 *
 *  基本二分查找：
 *  1） 在一个有序且不存在重复数据的有序集合中，查找给定值x的元素
 *
 *  二分查找的变形：
 *  1） 在一个有序且存在重复数据的有序集合众，查找第一个值等于给定值x的元素
 *  2） 在一个有序且存在重复数据的有序集合众，查找最后一个值等于给定值x的元素
 *  3） 在一个有序且存在重复数据的有序集合众，查找第一个大于给定值x的元素
 *  4） 在一个有序且存在重复数据的有序集合众，查找最后一个小于给定值x的元素
 *
 */
#include "algor.h"

///////////////////////////////////////////////////////////////////
// 基本二分查找
int bs_search(int x, int array[], int len)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = low + ((high - low)>>1);

		if (array[mid] > x) {
			high = mid - 1;
		} else if (array[mid] < x) {
			low = mid + 1;
		} else {		// array[mid] == x
			return mid;
		}
	}
	return -1;
}


///////////////////////////////////////////////////////////////////
// 查找第1个等于给定值x的元素
int bs_search_duplicates_first(int x, int array[], int len)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = low + ((high - low)>>1);

		if (array[mid] > x) {
			high = mid - 1;
		} else if (array[mid] < x) {
			low = mid + 1;
		} else {		// array[mid] == x
			if (mid == 0 || array[mid-1] != x)
				return mid;
			else
				high = mid - 1;
		}
	}
	return -1;
}

void test_01()
{
	int array[] = {1, 3, 4, 5, 6, 8, 8, 8, 11, 19};
	int len = sizeof(array)/sizeof(int);
	int pos;

	printf("Binary Search, test case 01\n");
	print_array(array, len);

	pos = bs_search_duplicates_first(8, array, len);
	printf("first %d's index = %d\n\n", 8, pos);
}

///////////////////////////////////////////////////////////////////
// 查找最后1个等于给定值x的元素
int bs_search_duplicates_last(int x, int array[], int len)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = low + ((high - low)>>1);

		if (array[mid] > x) {
			high = mid - 1;
		} else if (array[mid] < x) {
			low = mid + 1;
		} else {
			if (mid == (len-1) || array[mid+1] != x)
				return mid;
			else
				low = mid + 1;
		}
	}

	return -1;
}

void test_02()
{
	int array[] = {1, 3, 4, 5, 6, 7, 8, 8, 8, 11};
	int len = sizeof(array)/sizeof(int);
	int pos;

	printf("Binary Search, test case 02\n");
	print_array(array, len);

	pos = bs_search_duplicates_last(8, array, len);
	printf("last %d's index = %d\n\n", 8, pos);

	pos = bs_search_duplicates_last(88, array, len);
	printf("last %d's index = %d\n\n", 88, pos);
}

///////////////////////////////////////////////////////////////////
// 在一个有序且存在重复数据的有序集合众，查找第一个大于给定值x的元素
int bs_search_duplicates_first_larger(int x, int array[], int len)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = low + ((high - low) >> 1);

		if (array[mid] > x) {
			if (mid == 0 || array[mid-1] <= x)
				return mid;
			high = mid - 1;
		} else { 			// array[mid] <= x
			low = mid + 1;
		}
	}

	return -1;
}

void test_03()
{
	int array[] = {1, 3, 4, 5, 6, 7, 8, 8, 8, 11};
	int len = sizeof(array)/sizeof(int);
	int pos;
	int x = 7;

	printf("Binary Search, test case 02\n");
	print_array(array, len);

	pos = bs_search_duplicates_first_larger(x, array, len);
	printf("first larger than %x's elements is index = %d\n\n", x, pos);

	x = 11;
	pos = bs_search_duplicates_first_larger(x, array, len);
	printf("first larger than %x's elements is index = %d\n\n", x, pos);
}

///////////////////////////////////////////////////////////////////
// 在一个有序且存在重复数据的有序集合众，查找最后一个小于给定值x的元素
int bs_search_duplicates_last_small(int x, int array[], int len)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = low + ((high - low) >> 1);

		if (array[mid] >= x) {
			high = mid - 1;
		} else { 			// array[mid] < x
			if (mid == 0 || array[mid+1] > x)
				return mid;
			low = mid + 1;
		}
	}

	return -1;
}

void test_04()
{
	int array[] = {1, 3, 4, 5, 6, 7, 8, 8, 8, 11};
	int len = sizeof(array)/sizeof(int);
	int pos;
	int x = 7;

	printf("Binary Search, test case 04\n");
	print_array(array, len);

	pos = bs_search_duplicates_first_larger(x, array, len);
	printf("first larger than %x's elements is index = %d\n\n", x, pos);

	x = 11;
	pos = bs_search_duplicates_first_larger(x, array, len);
	printf("first larger than %x's elements is index = %d\n\n", x, pos);
}

///////////////////////////////////////////////////////////////////
void main()
{
	test_01();
	test_02();
	test_03();
	test_04();
}
