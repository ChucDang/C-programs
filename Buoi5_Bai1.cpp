#include <stdio.h>
int parent[100];
typedef struct
{
	int a, b, index;
} Edge;
typedef struct
{
	Edge edges[100];
	int n, m;
} Graph_Edge;
void init_Graph_Edge(Graph_Edge *G, int n)
{
	G->n = n;
	G->m = 0;
}
void add_edge_Edge(Graph_Edge *G, int a, int b, int index)
{
	if (a != b)
	{
		G->edges[G->m].a = a;
		G->edges[G->m].b = b;
		G->edges[G->m].index = index;
		G->m++;
	}
}
int findRoot(int u)
{
	if (parent[u] == u)
		return u;
	return findRoot(parent[u]);
}
int kruskal(Graph_Edge *G, Graph_Edge *T)
{
	int i, j, u, e;
	for (i = 1; i < G->m; i++)
	{
		int j = i;
		while (j > 0 && (G->edges[j].index < G->edges[j - 1].index))
		{
			Edge Temp;
			Temp = G->edges[j];
			G->edges[j] = G->edges[j - 1];
			G->edges[j - 1] = Temp;
			j--;
		}
	}
	init_Graph_Edge(T, G->n);
	for (u = 1; u <= G->n; u++)
		parent[u] = u;
	int sum_w = 0;
	for (e = 0; e < G->m; e++)
	{
		int u = G->edges[e].a;
		int v = G->edges[e].b;
		int w = G->edges[e].index;
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if (root_u != root_v)
		{
			add_edge_Edge(T, u, v, w);
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
	return sum_w;
}
int main()
{
	Graph_Edge G, T;
	int n, m, u, v, w;
	freopen("dt1.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_Graph_Edge(&G, n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge_Edge(&G, u, v, w);
	}
	int sum_w = kruskal(&G, &T);
	printf("%d\n", sum_w);
	for (int e = 0; e < T.m; e++)
	{
		if (T.edges[e].a < T.edges[e].b)
			printf("%d %d %d\n", T.edges[e].a, T.edges[e].b, T.edges[e].index);
		else
			printf("%d %d %d\n", T.edges[e].b, T.edges[e].a, T.edges[e].index);
	}
// Dung giai thuat Prim
//	printf("%d\n", Prim(&G, &T));
//    for (int i = 1; i <= T.n; i++)
//        for (int j = 1; j <= T.n; j++)
//            if (T.A[i][j] != 0)
//                printf("%d %d %d\n", i, j, T.A[i][j]);
}
