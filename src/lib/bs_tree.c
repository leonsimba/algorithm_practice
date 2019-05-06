/*
 * binary_search_tree.c - Binary search tree
 *
 * Copyright (C) 2016 ZhiPing.He. All rights reserved.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Author:
 * 	ZhiPing.He <zhiping.hzp@alibaba-inc.com>
 */

#include "algor.h"
#include "bs_tree.h"

static struct bs_tree bstree;

/* translate(T, u, v):
 * 	if u.p == NULL
 * 		T.root = v
 * 	elseif u == u.p.left
 * 		u.p.left = v
 * 	else
 * 		u.p.right = v
 * 	if v != NULL
 * 		v.p = u.p
 */
static void translate(struct bs_tree *tree, struct node *u, struct node *v)
{
	if (u->parent == NULL)
		tree->root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

/* Find the min key in tree x
 * bstree-mininum(x):
 * 		while x.left != NULL
 * 			x = x.left
 * 		return x
 */
struct node * bs_tree_mininum(struct node *x)
{
	while (x->left != NULL)
		 x = x->left;
	return x;
}

/* Find the max key in tree x
 * bstree-maxinum(x):
 * 		while x.right != NULL
 * 			x = x.right
 * 		return x
 */
struct node * bs_tree_maxinum(struct node *x)
{
	while (x->right != NULL)
		 x = x->right;
	return x;
}

/* bstree-successor(x):
 * 	if x.right != NULL
 * 		return tree-mininum(x.right)
 * 	y = x.p
 * 	while y!= NULL and x == y.right
 * 		x = y
 * 		y = y.p
 * 	return y
 */
struct node * bs_tree_successor(struct node *x)
{
	struct node *y;

	if (x->right != NULL) {
		y = bs_tree_mininum(x->right);
		return y;
	}
	y = x->parent;
	while (y != NULL && x == y->right) {
			x = y;
			y = y->parent;
	}
	return y;
}

/* bstree-predecessor(x):
 * 	if x.left != NULL
 * 		return tree-maxinum(x.left)
 * 	y = x.p
 * 	while y!= NULL and x == y.left
 * 		x = y
 * 		y = y.p
 * 	return y
 */
struct node * bs_tree_predecessor(struct node *x)
{
	struct node *y;

	if (x->left != NULL) {
		y = bs_tree_maxinum(x->left);
		return y;
	}
	y = x->parent;
	while (y != NULL && x == y->left) {
			x = y;
			y = y->parent;
	}
	return y;
}

/* tree_search(x, k):
 * 	while x != NULL and k != x.key
 * 		if k < x.key
 * 			x = x.left
 * 		else
 * 			x = x.right
 * 		return x
 */
struct node * bs_tree_search(struct node *x, int key)
{
	while (x != NULL && x->key != key) {
		if (x->key > key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

/* binary tree preorder walk */
void bs_tree_preorder_walk(struct node *root)
{
	int top = 0;
	struct node *p;
	struct node *array[MAX_NODE_NUM];

	if (!root)
		return;
	p = root;
	// Note: top must smaller than MAX_NODE_NUM
	while (p != NULL || top > 0) {
		while (p != NULL) {
			printf("%d ", p->key);
			array[top++] = p;  // push
			p = p->left;
		}
		if (top > 0) {
			p = array[--top]; // pop
			p = p->right;
		}
	}
	printf("\n");
}

/* binary tree inorder walk */
void bs_tree_inorder_walk(struct node *root)
{
	int top = 0;
	struct node *p = root;
	struct node *array[MAX_NODE_NUM];

	if (!root)
		return;

	while (p != NULL || top > 0) {
		while (p != NULL) {
			array[top++] = p;  // push
			p = p->left;
		}
		if (top > 0) {
			p = array[--top]; // pop
			printf("%d ", p->key);
			p = p->right;
		}
	}
	printf("\n");
}

/* binary tree postorder walk */
void bs_tree_postorder_walk(struct node *root)
{
	int top = 0;
	struct node *cur;
	struct node *pre = NULL;
	struct node *array[MAX_NODE_NUM];

	if (!root)
		return;

	array[top++] = root;
	while (top > 0) {
		cur = array[top-1];
		/* Print current node, if only of following condition is true:
		 * 1. The current node has no child;
		 * 2. The current node's chilren had been accessed.
		 */
		if ((cur->left == NULL && cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right))) {
			printf("%d ", cur->key);
			cur = array[--top]; // pop
			pre = cur;
		} else {
			if (cur->right != NULL)
				array[top++] = cur->right; 	// push
			if (cur->left != NULL)
				array[top++] = cur->left; 	// push
		}
	}
	printf("\n");
}

/* tree_insert(T, z):
 * 	y = NULL   // store the parent of z finally
 * 	x = T.root
 * 	while x != NULL
 *		y = x
 *		if z.key < x.key
 *			x = x.left
 *		else
 *			x = x.right
 *	z.p = y
 *	if y == NULL
 *		T.root = z	// Tree T was empty
 *	else if  z.key < y.key
 *		y.left = z
 *	else
 *		y.right = z
 */
int bs_tree_insert(struct bs_tree *tree, struct node *new)
{
	struct node *cur, *parent = NULL;

	if (tree->node_num > MAX_NODE_NUM)
		return -1;

	cur = tree->root;
	while (cur != NULL) {
		parent = cur;
		if (new->key < cur->key)
			cur = cur->left;
		else
			cur = cur->right;
	}

	new->parent = parent;
	if (parent == NULL)	/* Tree was empty */
		tree->root = new;
	else if (new->key < parent->key)
		parent->left = new;
	else
		parent->right = new;

	tree->node_num++;
	return 0;
}

/* tree-delete(T, z):
 * 		if z.left == NULL
 * 			translate(T, z, z.right)
 * 		elseif z.right == NULL
 * 			translate(T, z, z.left)
 * 		else y = tree-mininum(z.right)
 * 			if y.p != z
 * 				translate(T, y, y.right)
 * 				y.right = z.right
 * 				y.right.p = y
 * 			translate(T, z, y)
 * 			y.left = z.left
 * 			y.left.p = y
 */
void bs_tree_delete(struct bs_tree *tree, struct node *z)
{
	struct node *y = NULL;

	if (!tree || !z)
		return;

	/* delete node z from bs_tree */
	if (z->left == NULL) { 				// Only has right child or no child
		translate(tree, z, z->right);
	} else if (z->right == NULL) { 		// Only has left child or no child
		translate(tree, z, z->left);
	} else {
		y = bs_tree_mininum(z->right);
		if (y->parent != z) {
			translate(tree, y, y->right); // use y->right to replace y
			y->right = z->right;
			y->right->parent = y;
		}
		translate(tree, y, z); 			// use y to replace z
		y->left = z->left;
		y->left->parent = y;
	}
	/* release node z*/
	tree->node_num--;
	free(z);
}

struct node * bs_tree_create_node(int key)
{
	struct node *n;

	n = (struct node*)malloc(sizeof(struct node));
	if (!n) {
		perror("[bs_tree] create node failed");
		return NULL;
	}
	memset(n, 0, sizeof(struct node));
	n->key = key;
	return n;
}

void bs_tree_destroy(struct node *root)
{
	if (root == NULL)
		return;

	if (root->left != NULL)
		bs_tree_destroy(root->left);

	if (root->right != NULL)
		bs_tree_destroy(root->right);

	bstree.node_num--;
	free(root);
	return;
}


static int test(void)
{
	int i, ret = 0;
	int key[]={15,6,3,7,1,4,18,17,20,13,9,2};
	int num = sizeof(key)/sizeof(int);
	struct node *n, *tmp;

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

	n = bs_tree_search(bstree.root, 4);
	if (!n)
		goto failed;

	tmp = bs_tree_successor(n);
	if (tmp)
		printf("4 successor key = %d\n", tmp->key);

	n = bs_tree_search(bstree.root, 9);
	if (!n)
		goto failed;

	tmp = bs_tree_predecessor(n);
	if (tmp)
		printf("9 successor key = %d\n", tmp->key);

	/* walk the binary search tree */
	bs_tree_preorder_walk(bstree.root);
	bs_tree_inorder_walk(bstree.root);
	bs_tree_postorder_walk(bstree.root);

failed:
	bs_tree_destroy(bstree.root);
	return ret;
}
