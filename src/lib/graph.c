/*
 *  用邻接列表(Adjacent list)来描述图
 */
#include "algor.h"
#include "graph.h"

// 添加一条边
void add_edge(struct vertex *adj_list, unsigned int vertex_number,
			unsigned int from, unsigned int to)
{
	struct vertex *new1, *new2;

	if ((from == to) || (from > vertex_number) || (to > vertex_number))
		return;

	new1 = (struct vertex *) malloc(sizeof(struct vertex));
	if (!new1) {
		perror("malloc vertex");
		return;
	}

	new1->number = to;
	new1->next = adj_list[from].next;
	adj_list[from].next = new1;

	new2 = (struct vertex *) malloc(sizeof(struct vertex));
	if (!new2) {
		perror("malloc vertex");
		return;
	}
	new2->number = from;
	new2->next = adj_list[to].next;
	adj_list[to].next = new2;

	return;
}

void init_adj_list(struct vertex *adj_list, unsigned int vertex_number)
{
	int i;

	for (i = 0; i < vertex_number; i++) {
		adj_list[i].number = i;
		adj_list[i].next = NULL;
	}

	return;
}

void destroy_adj_list(struct vertex *adj_list, unsigned int vertex_number)
{
}

void scran_adj_list(struct vertex *adj_list, unsigned int vertex_number)
{
	int i;

	for (i = 0; i < vertex_number; i++) {
		struct vertex *p = adj_list + i;

		printf("%d ", p->number);
		while (p->next) {
			printf("-> %d ", p->next->number);
			p = p->next;
		}
		printf("\n");
	}
}
