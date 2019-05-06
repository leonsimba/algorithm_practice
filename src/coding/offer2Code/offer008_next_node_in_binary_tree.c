#include <stdio.h>

struct node {
	int key;
	struct node * left, * right, *parent;
};

struct node n1,n2,n3,n4,n5,n6,n7,n8,n9;

void build_tree()
{

	n1.key = 'a';
    n1.parent = NULL;
	n1.left = &n2;
	n1.right = &n3;

	n2.key = 'b';	
	n2.parent = &n1;
	n2.left = &n4;
    n2.right = &n5;

	n3.key = 'c';
    n3.parent = &n1;
	n3.left = &n8;
    n3.right = &n9;

	n4.key = 'd';
    n4.parent = &n2;
	n4.left = NULL;
    n4.right = NULL;
    
	n5.key = 'e';
    n5.parent = &n2;
	n5.left = &n6;
    n5.right = &n7;

	n6.key = 'h';
    n6.parent = &n5;
	n6.left = NULL;
    n6.right = NULL;

	n7.key = 'i';
    n7.parent = &n5;
	n7.left = NULL;
    n7.right = NULL;

	n8.key = 'f';
    n8.parent = &n3;
	n8.left = NULL;
    n8.right = NULL;
	
	n9.key = 'g';
    n9.parent = &n3;
	n9.left = NULL;
    n9.right = NULL;
}

struct node * find_next(struct node *p)
{
	struct node * next;
	int left = 0;

	if (p->right) {
		next = p->right;		
		while (next->left) {
			next = next->left;
		}
		return next;
	}	

	// p->right == NULL &&)
	if (p->parent) {
		if (p->parent->left == p) {		// left node
			return p->parent;
		} else {						// right node
			next = p->parent;
			while (next->parent) {
				if (next->parent->left == next)
					left = 1;
				next = next->parent;
			}
			if (left)
				return next;
			else 
				return NULL;

		}
	} else {
		return NULL;
	}
}

void main()
{
	struct node *next;

	build_tree();
	
	next = find_next(&n7);
	if (next)
		printf("%c\n", next->key);

#if 0
	next = find_next(&n9);
	if (next)
		printf("%c\n", next->key);
#endif

	next = find_next(&n5);
	if (next)
		printf("%c\n", next->key);

	next = find_next(&n4);
	if (next)
		printf("%c\n", next->key);

	return;
}
