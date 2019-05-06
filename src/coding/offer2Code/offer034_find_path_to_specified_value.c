/*
 * Copyright (C) 2016 ZhiPing He. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author: Zhiping He
 *
 * 剑指Offer2：034
 * 	   输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 	   路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 *
 *     例：和为22的路径有两条：{10, 5, 7} {10, 12}
 *   	   10
 *        / \
 *       5   12
 *      / \
 *     4  7
 *
 */
#include "algor.h"

static int top = 0;

void print_path(struct node **path, int top)
{
	int i;

	for (i = 0; i < top; i++) {
		printf("key = %d, ", path[i]->key);
	}
	printf("\n");
}

void find_path(struct node *node, int value, struct node** path, int cur_sum)
{
	path[top++] = node; // push
	cur_sum = cur_sum + node->key;

	if (node->left == NULL && node->right ==NULL) {
		if (cur_sum == value)
			print_path(path, top);
	}

	if (node->left)
		find_path(node->left, value, path, cur_sum);
	if (node->right)
		find_path(node->right, value, path, cur_sum);

	top--; // pop
}

/*
 * Return:
 *    0	- not find
 *    1 - find at least one path
 */
int find_all_path(struct bs_tree *tree, int value)
{
	struct node * cur = tree->root;
	struct node **path;
	int len = tree->node_num * sizeof(struct node *);
	int cur_sum = 0;

	memset(path, 0, len);

	path = (struct node **) malloc(len);
	if (!path)
		return 0;

	top = 0;
	find_path(cur, value, path, cur_sum);
}

int main(void)
{
	int i, ret = 0;
	int key[]={10, 5, 4, 7, 12};
	int num = sizeof(key)/sizeof(int);
	struct node *n, *tmp;
	struct bs_tree bstree;

	memset(&bstree, 0, sizeof(struct bs_tree));
	for (i = 0; i < num; i++) {
		n = bs_tree_create_node(key[i]);
		if (!n) {
			ret = -ENOMEM;
			goto failed;
		}

		ret = bs_tree_insert(&bstree, n);
		if (ret < 0)
			goto failed;
	}

	find_all_path(&bstree, 22);

failed:
	bs_tree_destroy(bstree.root);
	return ret;
}
