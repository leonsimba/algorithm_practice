/*
 * 图的搜索: 宽度优先搜索和深度优先搜索
 */

#include "algor.h"

#define MAX		8

// 图的宽度优先搜索
void bfs_graph(struct vertex *adj_list, unsigned int vertex_number, int s)
{
	int fifo[vertex_number], start = 0, end = 0;
	int visited[vertex_number];	// 记录顶点是否已经访问过
	struct vertex *list;

	if (s > vertex_number || s < 0)
		return;

	memset(visited, 0 , sizeof(int) * vertex_number);

	printf("%d", s);
	fifo[end++] = s;
	visited[s] = 1;

	while ((end-start) != 0) {
		int n = fifo[start++];
		struct vertex * p = adj_list + n;

		while ((p = p->next)) {
			int v = p->number;

			if (visited[v] == 0) {
				printf(" -> %d", v);
				visited[v] = 1;
				fifo[end++] = v;
			}
		}
	}
	printf("\n");
}

/*
 * Test case:
 *
 * 0 --- 1 --- 2
 * |     |	   |
 * 3 --- 4 --- 5
 *		 |	   |
 *		 6 --- 7
 *
 */
int main(int argc, char *argv[])
{

	struct vertex adj_list[MAX];


	// Step1: create a graph
	init_adj_list(adj_list, MAX);
	add_edge(adj_list, MAX, 0, 1);
	add_edge(adj_list, MAX, 0, 3);
	add_edge(adj_list, MAX, 1, 2);
	add_edge(adj_list, MAX, 1, 4);
	add_edge(adj_list, MAX, 2, 5);
	add_edge(adj_list, MAX, 3, 4);
	add_edge(adj_list, MAX, 4, 5);
	add_edge(adj_list, MAX, 4, 6);
	add_edge(adj_list, MAX, 5, 7);
	add_edge(adj_list, MAX, 6, 7);

	// Step2: check if we create the right graph
	scran_adj_list(adj_list, MAX);

	printf("\n");

	// Step3: start to do BFS
	bfs_graph(adj_list, MAX, 4);

	return 0;
}
