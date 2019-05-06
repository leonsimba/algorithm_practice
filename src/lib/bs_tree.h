#ifndef BS_TREE_H
#define BS_TREE_H

#define MAX_NODE_NUM 	(128)

struct node {
	int key;
	struct node * left;
	struct node * right;
	struct node * parent;
};

struct bs_tree {
	struct node *root;
	int node_num; 		/* node numbers in bs_tree */
};

struct node * bs_tree_mininum(struct node *x);
struct node * bs_tree_maxinum(struct node *x);
struct node * bs_tree_successor(struct node *x);
struct node * bs_tree_predecessor(struct node *x);
struct node * bs_tree_search(struct node *x, int key);

void bs_tree_preorder_walk(struct node *x);
void bs_tree_inorder_walk(struct node *x);
void bs_tree_postorder_walk(struct node *x);

int bs_tree_insert(struct bs_tree *tree, struct node *new);
void bs_tree_delete(struct bs_tree *tree, struct node *z);

struct node * bs_tree_create_node(int key);
void bs_tree_destroy(struct node *tree);

#endif
