/* [LeetCode-081] Search in Rotated Sorted Array II 在旋转有序数组中搜索之二
 *
 * 题目:
 *    Follow up for "Search in Rotated Sorted Array":
 *    What if duplicates are allowed?
 *
 *    Would this affect the run-time complexity? How and why?
 *    Write a function to determine if a given target is in the array.
 *
 * 解题思路:
 *    这和 Search in Rotated Sorted Array(在旋转有序数组中搜索)类似，
 *    但是，现在数组中允许出现重复数字，这个会影响我们选择哪半边继续搜索，
 *    由于之前那道题不存在相同值，在比较中间值和最右值时完全符合下面规律:
 *    1) 如果中间的数小于最右边的数，则右半段是有序的，
 *    2) 若中间数大于最右边数，则左半段是有序的
 *
 *    但是如果有重复值，则会出现两种情况r:
 *    [3 1 1] 和 [1 1 3 1]
 *
 *    对于这两种情况中间值等于最右值时，目标值3既可以在左边又可以在右边，那怎么办么?
 *    对于这种情况其实处理非常简单，只要把最右值向左一位即可继续循环，
 *    如果还相同则继续移，直到移到不同值为止，
 *    然后, 其他部分还采用 Search in Rotated Sorted Array 在旋转有序数组中搜索 中的方法.
 *
 */
#include "algor.h"

int bs_search_rotated_sorted_array_II(int x, int array [], int len)
{
	int mid, low, high;

	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = low + ((high - low) >> 1);

		if (array[mid] == x)
			return mid;

		if (array[mid] < array[high]) {	// right part is sorted
			if (array[mid] < x && x < array[high])
				low = mid + 1;
			else
				high = mid - 1;
		} else if (array[mid] > array[high]) { // left part is sorted
			if (array[low] < x && x < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		} else {
			--high;
		}
	}

	return -1;
}

void main()
{
	int array[] = {6, 7, 0, 1, 2, 4, 5, 5};
	int len = sizeof(array)/sizeof(int);
	int x = 4, index;

	print_array(array, len);
	index = bs_search_rotated_sorted_array_II(x, array, len);
	printf("x =%d, index = %d\n", x, index);

}
