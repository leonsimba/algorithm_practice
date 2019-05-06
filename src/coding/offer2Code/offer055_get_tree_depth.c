/*
 * 剑指Offer2：055
 *
 * 题目055:
 *	  输入一棵二叉树，求该树的深度。
 *	  从根结点到叶结点依次经过的结点(含根、叶结点)形成树的一条路径，最长路径的长度为树的深度。
 *
 * Author: Zhiping He
 * Date: 2018-01-01
 *
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "bs_tree.h"

int get_tree_depth(struct node * root)
{
	int left_depth, right_depth;

	if (!root)
		return 0;

	left_depth = get_tree_depth(root->left);
	right_depth = get_tree_depth(root->right);

	return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

int main()
{
	int i, ret = 0, depth;
	int key[]={5, 3, 2, 4, 7, 6, 8};
	int num = sizeof(key)/sizeof(int);

	struct node * k_node;
	struct bs_tree bstree;

	memset(&bstree, 0, sizeof(struct bs_tree));

	for (i = 0; i < num; i++) {
		struct node *n;
		n = bs_tree_create_node(key[i]);
		if (!n) {
			ret = -ENOMEM;
			goto failed;
		}

		ret = bs_tree_insert(&bstree, n);
		if (ret < 0)
			goto failed;
	}

	// for debug
	depth = get_tree_depth(bstree.root);
	printf("The depth of the tree is %d\n", depth);

failed:

	return 0;
}
