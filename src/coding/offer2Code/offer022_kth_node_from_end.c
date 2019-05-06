/*
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：022
 *    输入一个链表，输出该链表中倒数第k个结点, k为正整数，取值从1开始。
 *
 */
#include "algor.h"

static int max = 10;

struct s_item *get_kth_node_from_end(struct s_item *head, int kth)
{
	struct s_item *fast, *slow;

	if (kth < 1) {
		printf("Invaild kth = %d\n", kth);
		return NULL;
	}

	fast = slow = head;
	while(--kth > 0) {
		fast = fast->next;
		if (!fast) {
			printf("The kth = %d is larger than the length of list\n", kth);
			return NULL;
		}
	}

	while (!fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main()
{
	int ret, kth;
	int array[]={2, 3, 1, 0, 2, 5, 3};
	int len = sizeof(array)/sizeof(int);

	struct slist_head head;
	struct s_item *ptr;

	init_slist(&head);
	ret = insert_items_to_slist(&head, array, len);
	if (ret < len) {
		printf("Insert failed, ret = %d, len = %d\n", ret, len);
		exit(-1);
	}

	kth = len;
	ptr = get_kth_node_from_end(head.next, kth);
	if (ptr)
		printf("The %dth from the end fo list is %d\n", kth, ptr->value);

	free_slist(&head);

	return 0;
}
