#ifndef GRAPH_H
#define GRAPH_H

// 描述一个顶点(vertex)
struct vertex {
	int data;				// user data
	int number;				// vertex number
	struct vertex *next;	// 该顶点相邻的其他顶点
};

void init_adj_list(struct vertex *, unsigned int);
void scran_adj_list(struct vertex *, unsigned int);
void destroy_adj_list(struct vertex *, unsigned int);
void add_edge(struct vertex *, unsigned int, unsigned int, unsigned int);
#endif
