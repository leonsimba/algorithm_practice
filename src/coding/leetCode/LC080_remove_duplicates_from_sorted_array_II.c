/* [LeetCode-081] Remove Duplicates from Sorted Array II 有序数组中去除重复项之二
 *
 * 题目:
 *    Follow up for "Remove Duplicates":
 *    What if duplicates are allowed at most twice?
 *
 *    For example,
 *    	Given sorted array A = [1,1,1,2,2,3],
 *
 *    	Your function should return length = 5, and A is now [1,1,2,2,3].
 *
 * 思路:
 *    这里允许最多重复的次数是两次，那么需要用一个变量count来记录还允许有几次重复
 *    count初始化为1，如果出现过一次重复，则count增1，那么下次再出现重复，快指针直接前进一步;
 *    如果这时候不是重复的，则count恢复1，
 *    由于整个数组是有序的，所以一旦出现不重复的数，则一定比这个数大，此数之后不会再有重复项。
 */
#include <stdio.h>

int remove_duplicates(int array[], int len)
{
	int i, last, index=0, count = 1;

	last = array[0];
	for (i = 1; i < len; i++) {
		if (array[i] == last) {
			if (count < 2) {
				array[++index ] = array[i];
			}
			count++;
		} else {
			count = 1;
			last = array[i];
			array[++index ] = array[i];
		}
	}

	return index + 1;
}

///////////////////////////////////////////////////////////////////////////////
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
	int array[] = {1, 1, 2, 3, 3, 3, 4, 5};
	int len = sizeof(array)/sizeof(int);

	print_array(array, len);
	len = remove_duplicates(array, len);
	print_array(array, len);
}
