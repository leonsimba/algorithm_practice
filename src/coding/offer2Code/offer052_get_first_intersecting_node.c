/*
 * Copyright (C) 2018 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：052
 *     输入两个链表，判断两者是否相交，如果相交，找出它们相交的第1个节点.
 *     如下图，两个链表相交的第1个节点为6
 *     1 -> 2 ->3
 *               \
 *      4 -> 5 -> 6 -> 7
 *
 */
#include "algor.h"

struct s_item * get_tail_and_length(struct slist_head *list, int *len)
{
	struct s_item * tail = list->next;
	int count = 1;

	while (tail->next) {
		tail = tail->next;
		count++;
	}

	*len = count;	// now we get the length of list

	return tail;
}

struct s_item * get_first_intersecting_node(struct slist_head *long_list,
		struct slist_head *short_list, int dis)
{
	struct s_item * long_p = long_list->next;
	struct s_item * short_p = short_list->next;

	// move forward p1 in the longer list
	while (0 < dis--)
		long_p = long_p->next;

	// let's find the first same node
	while(long_p != short_p) {
		long_p = long_p->next;
		short_p = short_p->next;
	};

	return long_p;
}

struct s_item *get_intersecting_node_in_list(struct slist_head *l1,
		struct slist_head *l2)
{
	struct s_item *tail1, *tail2;
	int len1, len2, dis;

	if (!l1 || !l2 || !l1->next || !l2->next)
		return NULL;

	if (l1->next == l2->next)
		return l1->next;

	tail1 = get_tail_and_length(l1, &len1);
	tail2 = get_tail_and_length(l2, &len2);

	if (tail1 != tail2) {
		printf("Those two list does not intersect\n");
		return NULL;
	}

	if (len1 > len2) {
		dis = len1 - len2;
		return get_first_intersecting_node(l1, l2, dis);
	} else {
		dis = len2 - len1;
		return get_first_intersecting_node(l2, l1, dis);
	}
}

int main()
{
	int ret;
	int array1[]={1, 2, 3, 6, 7};
	int array2[]={4, 5};
	int len;

	struct slist_head list1, list2;
	struct s_item *ptr;

	// create list1
	init_slist(&list1);
	len = sizeof(array1)/sizeof(int);
	ret = insert_items_to_slist(&list1, array1, len);
	if (ret < len) {
		printf("Insert failed, ret = %d, len = %d\n", ret, len);
		exit(-1);
	}

	// create list2
	init_slist(&list2);
	len = sizeof(array2)/sizeof(int);
	ret = insert_items_to_slist(&list2, array2, len);
	if (ret < len) {
		printf("Insert failed, ret = %d, len = %d\n", ret, len);
		exit(-1);
	}

	// Now let's make an intersection
	ptr = get_item_in_slist(&list1, 6);
	list2.tail->next = ptr;
	list2.tail = list1.tail;
	print_slist(&list2);
	print_slist(&list1);

	// Now let's find the first intersecting node
	ptr = get_intersecting_node_in_list(&list1, &list2);
	if (ptr)
		printf("The intersecting node is %d\n", ptr->value);

	free_slist(&list1);
	free_slist(&list2);

	return 0;
}
