/*
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：024题
 *     原地反转一个单链表
 *
 */
#include "algor.h"

#define N	6	// list s_item number

// method_v1
struct s_item * reverse_list(struct s_item *head)
{
	struct s_item *new_head;
	struct s_item *cur, *tail;

	if (!head)
		return NULL;

	new_head = tail = head;
	cur = head->next;
	while(cur != NULL) {
		tail->next = cur->next;
		cur->next = new_head;
		new_head = cur;
		cur = tail->next;
	}
	return new_head;	// return new list head
}

// method_v2: recursive reverse list
#if 0
static struct s_item * new_head;
struct s_item *recursive_reverse_list(struct s_item *pre, struct s_item *cur)
{
	if (!cur) {
		new_head = pre;
		return NULL;
	}

	recursive_reverse_list(cur, cur->next);
	cur->next = pre;
	pre->next = NULL;

	return;
}
#endif

int main()
{
	int i;
	struct slist_head list;
	struct s_item *head, *ptr;

	// build a list for test
	init_slist(&list);
	for (i = 1; i <= N; i++) {
		ptr = insert_item_to_slist(&list, i);
		if (!ptr)
			exit(-1);
	}
	print_slist(&list);

	// test method1
	head = reverse_list(list.next);
	list.tail = list.next;
	list.next = head;
	print_slist(&list);

	free_slist(&list);
	return 0;
}
