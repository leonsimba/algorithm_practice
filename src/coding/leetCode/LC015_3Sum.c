/* [LeetCode] 3Sum 三数之和
 *
 * Description:
 *    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 *    Find all unique triplets in the array which gives the sum of zero.
 *
 *    Note:
 *      Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *    	The solution set must not contain duplicate triplets.
 *
 *    	For example, given array S = {-1 0 1 2 -1 -4},
 *
 *    	A solution set is:
 *    		    (-1, 0, 1)
 *    			(-1, -1, 2)
 */
#include <stdio.h>

int three_sum(int sum, int array [], int len)
{
	int low, mid, high;
	int count = 0;

	low = 0;
	high = len - 1;
	mid = high -1;

	// sorted the array first
	while (low+1 < high) {
		int s = array[low] + array[mid] + array[high];

		if (s < sum) {
			low = low + 1;
		} else if (s > sum) {
			mid = mid - 1;
			if (mid == low) {
				high = high - 1;
				mid = high - 1;
			}
		} else {
			printf("(%d, %d, %d) ", array[low], array[mid], array[high]);
			count++;
			high = len - count -1;
			mid = high - 1;
			low = 0;
		}
	}
	printf("\n");

	return count;
}

void print_array(int *array, int len)
{
	int i;

	printf("Array len =%d : [", len);
	for (i = 0; i < len; i++)
		printf("%d, ", array[i]);
	printf("]\n\n");
}

void main()
{
	int array[] = {-5, -4, -1, -1, 0, 1, 2};
	int len = sizeof(array)/sizeof(int);
	int sum, count;

	print_array(array, len);

	sum = 0;
	count = three_sum(sum, array, len);
	printf("sum = %d, count = %d\n\n", sum, count);

	sum = -6;
	count = three_sum(sum, array, len);
	printf("sum = %d, count = %d\n\n", sum, count);
}
