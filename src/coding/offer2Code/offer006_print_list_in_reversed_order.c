/*
 * Copyright (C) 2018 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：006
 *    从尾到头打印链表
 *
 */
#include "algor.h"

void reverse_print(struct s_item *node)
{
	if (node == NULL) {
		return;
	}

	reverse_print(node->next);
	printf("%d ", node->value);
}

int main()
{
	struct slist_head list;
	int array[]={1, 2, 3, 6, 7};
	int len = sizeof(array)/sizeof(int);
	int ret;

	init_slist(&list);
	ret = insert_items_to_slist(&list, array, len);
	if (ret < len) {
		printf("Insert failed, ret = %d, len = %d\n", ret, len);
		exit(-1);
	}
	print_slist(&list);

	reverse_print(list.next);
	printf("\n");

	free_slist(&list);
	return 0;
}
