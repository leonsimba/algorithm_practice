#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

struct s_item {
	int value;
	struct s_item *next;
};

struct d_item {
	int value;
	struct d_item *pre, *next;
};

struct slist_head {
	struct s_item *next;		// point the first item in list
	struct s_item *tail;
};

void print_slist(struct slist_head *);
void free_slist(struct slist_head *);
void init_slist(struct slist_head *);
struct s_item * insert_item_to_slist(struct slist_head *, int);
int insert_items_to_slist(struct slist_head *, int *, int);
struct s_item *get_item_in_slist(struct slist_head *, int);

#endif
