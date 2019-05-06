/*
 * Basic Operation of single linked list
 */
#include "list.h"

// return 0 ,if insert success
struct s_item *insert_item_to_slist(struct slist_head *list, int value)
{
	struct s_item *head, *ptr;

	if (!list)
		return NULL;

	// alloc an item
	ptr = (struct s_item *)malloc(sizeof(struct s_item));
	if (!ptr)
		return NULL;
	ptr->value = value;
	ptr->next = NULL;

	head = list->next;
	if (!head) {
		list->next = ptr;
		list->tail = ptr;
		return ptr;
	}

	list->tail->next = ptr;
	list->tail = ptr;

	return ptr;
}

// return how many items inserted successfully
int insert_items_to_slist(struct slist_head *list, int *array, int len)
{
	int i;
	struct s_item *ptr;

	if (!list)
		return 0;

	for (i = 0; i < len; i++) {
		ptr = insert_item_to_slist(list, array[i]);
		if (!ptr)
			return i;
	}
	return len;
}

struct s_item *get_item_in_slist(struct slist_head *list, int value)
{
	struct s_item *ptr;

	if (!list)
		return NULL;

	ptr = list->next;
	while (ptr) {
		if (ptr->value == value)
			return ptr;
		ptr = ptr->next;
	}

	return NULL;
}

void init_slist(struct slist_head *list)
{
	if (!list)
		return;

	list->next = NULL;
	list->tail = NULL;
}

void free_slist(struct slist_head *list)
{
	struct s_item *head;

	if (!list)
		return;

	head = list->next;
	while (head != NULL) {
		list->next = head->next;
		free(head);
		head = list->next;
	}

	list->tail = NULL;
}

void print_slist(struct slist_head *list)
{
	struct s_item *head;

	if (!list)
		return;

	head = list->next;
	while(head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

