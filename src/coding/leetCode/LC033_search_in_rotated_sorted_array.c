/* [LeetCode-033] Search in Rotated Sorted Array 在旋转有序数组中搜索
 *
 * 题目:
 *    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 *    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 *    You are given a target value to search. If found in the array return its index, otherwise return -1.
 *    You may assume no duplicate exists in the array.
 *
 * 思路:
 *    在循环有序数组中搜索一个给定值，若存在返回坐标，若不存在返回-1.
 *    假设，数组包含的元素为，0 1 2 4 5 6 7，那么该数组可能有下面7种状态：
 *
 *    第1种：0　　1　　2　　4　　5　　6　　7
 *    第2种：7　　0　　1　　2　　4　　5　　6
 *    第3种：6　　7　　0　　1　　2　　4　　5
 *    第4种：5　　6　　7　　0　　1　　2　　4
 *    第5种：4　　5　　6　　7　　0　　1　　2
 *    第6种：2　　4　　5　　6　　7　　0　　1
 *    第7种：1　　2　　4　　5　　6　　7　　0
 *
 *    我们还是考虑二分搜索法，但是难点在于不知道原数组在哪旋转了.
 *    二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，
 *    我们观察上面循环有序数组的7种形式，可以得出如下规律：
 *    1) 如果中间的数小于最右边的数，则右半段是有序的，
 *    2) 如果中间数大于最右边数，则左半段是有序的，
 *    我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了.
 */
#include "algor.h"

int bs_search_rotated_sorted_array_I(int x, int array [], int len)
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
		} else {						// left part is sorted
			if (array[low] < x && x < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}

	return -1;
}

void main()
{
	int array[] = {6, 7, 0, 1, 2, 4, 5};
	int len = sizeof(array)/sizeof(int);
	int x = 4, index;

	print_array(array, len);
	index = bs_search_rotated_sorted_array_I(x, array, len);
	printf("x =%d, index = %d\n", x, index);

}
