/*
 * Author: Zhiping He
 *
 * 剑指Offer2：054
 *
 * 题目054:
 *    给定一颗二叉搜索树，请找出其中的第k小的结点。
 *    例如，如下图, 按结点数值大小顺序第3个结点的值为4。
 *          5
 *         / \
 *        3   7
 *       / \  / \
 *      2  4  6  8
 *
 */
#include "algor.h"

struct node * get_kth_node(struct bs_tree *tree, int k)
{
	int seq = 0;
	int top = 0;
	struct node *cur = tree->root;
	struct node ** stack;
	int len = tree->node_num * sizeof(struct node *);

	stack = (struct node **)malloc(len);
	if (!stack) {
		printf("malloc stack failed\n");
		return NULL;
	}
	memset(stack, 0, len);

	while (cur || top > 0) {
		struct node * k_node;
		while (cur) {
			stack[top++] = cur;
			cur = cur->left;
		}

		if (top > 0) {
			k_node = stack[--top];
			if (++seq == k)
				return k_node;
			cur = k_node->right;
		}
	}
}

int main()
{
	int i, ret = 0;
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
	bs_tree_inorder_walk(bstree.root);

	int kth = 9;
	k_node = get_kth_node(&bstree, kth);
	if (k_node) {
		printf("the Kth %d node's key = %d\n", kth, k_node->key);
	} else {
		printf("the Kth %d node was not exist\n", kth);
	}

failed:

	return 0;
}
