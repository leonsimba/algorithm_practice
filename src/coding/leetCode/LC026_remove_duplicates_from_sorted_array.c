/* [LeetCode-026] Remove Duplicates from Sorted Array 有序数组中去除重复项
 *
 * Description:
 *
 * 		Given a sorted array nums, remove the duplicates in-place such that
 * 		each element appear only once and return the new length.
 *
 *		Do not allocate extra space for another array, you must do this by
 *		modifying the input array in-place with O(1) extra memory.
 *
 * Example 1:
 * 		Given nums = [1,1,2],
 *		Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 *	  	It doesn't matter what you leave beyond the returned length.
 *
 *
 * 解题思路:
 * 		使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字.
 * 		如果两个指针指的数字相同，则快指针向前走一步;
 * 		如果不同，则两个指针都向前走一步;
 * 		这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数字的个数.
 */
#include <stdio.h>

int remove_duplicate(int * array, int len)
{
	int i, last, count = 0;

	last = array[0];

	for (i = 1; i < len; i++) {
		if (array[i] != last) {
			last = array[i];
			array[++count] = array[i];
		}
	}

	return count + 1;
}

void print_array(int *array, int len)
{
	int i;

	printf("len =%d\n", len);
	for (i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void main()
{
	int array[] = {1, 1, 2, 3, 3, 4};
	int len = sizeof(array)/sizeof(int);

	print_array(array, len);
	len = remove_duplicate(array, len);
	print_array(array, len);
}
