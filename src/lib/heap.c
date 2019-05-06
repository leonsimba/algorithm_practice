/*
 * heap.c - heap sort
 *
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: ZhiPing He <zhiping.hzp@alibaba-inc.com>
 *
 */

#include "algor.h"
#include "heap.h"

#define LEFT_CHILD(i)	( (2 * i) + 1 )		// left_child = 2 * i
#define RIGHT_CHILD(i)	( (2 * i) + 2 )		// right_child = 2 * i + 1
#define PARENT(i)	( (i - 1) / 2 )		// parent = i / 2

unsigned int heap_size;

/* max_heapify(A, i):
 *	lchild = LEFT_CHILD(i)
 *	rchild = RIGHT_CHILD(i)
 *      if lchild <= heap_size && A[lchild] > A[i]
 *		largest = lchild
 *      else
 *		largest = i
 *      if rchild <= heap_size && A[rchild] > A[i]
 *		largest = rchild
 *	if largest != i
 *		exchange A[i] with A[largest]
 *		max-heapify(A, largest)
 */
void max_heapify(int a[], int i)
{
	int lchild, rchild;
	int largest;

	lchild = LEFT_CHILD(i);
	rchild = RIGHT_CHILD(i);

	if (lchild < heap_size && a[lchild] > a[i])
		largest = lchild;
	else
		largest = i;

	if (rchild < heap_size && a[rchild] > a[largest])
		largest = rchild;

	if (largest != i) {
		exchange(a, largest, i);
		max_heapify(a, largest);
	}
}

/* build_max_heap(A):
 *	A.heap_size = A.length
 *	for i = A.lengh/2 downto 1
 *		max-heapify(A, i)
 */
void build_max_heap(int a[], unsigned int array_length)
{
	int i;

	heap_size = array_length;
	// for i = heap_size/2 downto 1
	for (i = PARENT(heap_size -1)/2; i >= 0; i--)
		max_heapify(a, i);
}

/* heap_sort(A):
 *	build-max-heap(A)
 *	for i = A.lengh downto 2
 *		exchange A[1] with A[i]
 *		A.heap_size = A.heap_size - 1
 *		max-heapify(A, 1)
 */
void heap_sort(int a[], unsigned int length)
{
	int i;

	build_max_heap(a, length);
	for (i = length - 1; i >= 1; i--) {
		exchange(a, 0, i);
		heap_size = heap_size - 1;
		max_heapify(a, 0);
	}
}

int heap_test()
{
	int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	unsigned int array_length;

	array_length = sizeof(a)/sizeof(int);
	build_max_heap(a, array_length);
	print_array(a, array_length);

	heap_sort(a, array_length);
	print_array(a, array_length);

	return 0;
}
