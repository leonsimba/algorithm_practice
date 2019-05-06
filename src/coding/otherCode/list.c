#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL, *tail = NULL;

struct node * add(int data)
{
	struct node *new;

	new = malloc(sizeof(struct node));
	if (!new) {
		return NULL;
	}

	new->data = data;
	new->next = NULL;
	if (tail)
		tail->next = new;
	tail = new;

	return new;
}

void list_scan()
{
	struct node *p;

	p = head;
	while (p) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////
/*
 * Case1: list reverse
 */

void list_reverse()
{
	struct node *h = head;
	struct node *p1, *p2;

	if (h == NULL || h->next == NULL)
		return;

	p1 = h->next;
	p2 = p1->next;
	h->next = NULL;

	while (p2) {
		p1->next = h;
		h = p1;
		p1 = p2;
		p2 = p2->next;
	}

	p1->next = h;
	head = p1;
}

/*************************************************************************/
/*
 * Case2:
 *
 *     3 -> 6 -> 10 -> 5 -> 2
 *     k = k
 *	   3 -> 2 -> 5 -> 6 -> 10
 */
void list_middle_x(int x)
{
	struct node *ltail, *rhead, *rtail, *cur;

	cur = head;
	ltail = rhead = rtail = NULL;

	if (cur->next == NULL) {
		return;
	}

	while (cur) {
		// if data < x, then link to the left list
		if (cur->data < x) {
			if (ltail != NULL)
				ltail->next = cur;
			ltail = cur;
		}

		// if data < x, then link to the right list
		if (cur->data >= x) {
			if (rhead == NULL) {
				rhead = rtail = cur;
			} else {
				rtail->next = cur;
				rtail = cur;
			}
		}
		cur = cur->next;
	}

	ltail->next = rhead;
	rtail->next = NULL;
}


void test_case2()
{
	head = add(3); add(6); add(10); add(5); add(2);

	list_scan();
	list_middle_x(5);
	list_scan();
}

/*************************************************************************/
/* case 3:
 *    a1 -> a2 -> a3 -> b1 -> b2 -> b3
 *    To:
 *    a1 -> b1 -> a2 -> b2 -> a3 -> b3
 */
void list_interval_crossing(void)
{
	struct node *p1, *p2, *middle;
	struct node *tmp;

	p1 = p2 = head;

	while(p2) {
		// p2 move 2 once
		p2 = p2 ->next;
		if (!p2)
			break;
		p2 = p2->next;

		// p1 move 1 once
		p1 = p1->next;
	}
	printf("middle node = %d\n", p1->data);

	middle = p1;
	p2 = head;
	while (p1) {
		tmp = p2->next;

		p2->next = p1;
		p1 = p1->next;

		if (tmp == middle)
			break;

		p2->next->next = tmp;
		p2 = tmp;
	}
}


void test_case3()
{
	//head = add(1); add(3); add(5); add(2); add(4); add(6);
	head = add(1); add(3); add(5); add(2); add(4);

	list_scan();
	list_interval_crossing();
	list_scan();
}

////////////////////////////////////////////////////////////////////////////

void test_case1()
{

	head = add(1); add(2); add(3); add(4); add(5); add(6);

	list_scan();
	list_reverse();
	list_scan();
}
/////////////////////////////////////////////////////////////////////////////

void main()
{
	test_case3();
}
