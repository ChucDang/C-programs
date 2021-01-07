#include <stdio.h>
int p[100];
int mark[100];
int pi[100];
typedef struct
{
	int A[100][100];
	int n;
} Graph_A_dinh_dinh;
void init_graph_A_dinh_dinh(Graph_A_dinh_dinh *G, int n)
{
	G->n = n;
	for (int i = 1; i <= G->n; i++)
	{
		for (int k = 1; k <= G->n; k++)
		{
			G->A[i][k] = 0;
		}
	}
}
int Prim(Graph_A_dinh_dinh *G, Graph_A_dinh_dinh *T)
{
	init_graph_A_dinh_dinh(T, G->n);
	int i, u, v;
	for (u = 1; u <= G->n; u++)
		pi[u] = 1000;
	pi[1] = 0;
	for (v = 1; v <= G->n; v++)
		if (G->A[1][v] != 0)
		{
			pi[v] = G->A[1][v];
			p[v] = 1;
		}
	for (i = 1; i <= G->n; i++)
		mark[i] = 0;
	mark[1] = 1;
	int sum_w = 0;
	for (i = 1; i < G->n; i++)
	{
		int min_dist = 1000, min_u;
		for (u = 1; u <= G->n; u++)
			if (mark[u] == 0)
			{
				if (min_dist > pi[u])
				{
					min_dist = pi[u];
					min_u = u;
				}
			}
		u = min_u;
		mark[min_u] = 1;
		T->A[p[u]][u] = min_dist;
		sum_w += min_dist;
		for (v = 1; v <= G->n; v++)
			if (G->A[u][v] != 0 && mark[v] == 0)
				if (pi[v] > G->A[u][v])
				{
					pi[v] = G->A[u][v];
					p[v] = u;
				}
	}
	return sum_w;
}
int main()
{
	Graph_A_dinh_dinh G, T;
	int n, m, u, v, w;
	freopen("dt1.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	G.n = n;
	for (int e = 1; e <= m; e++)
	{
		scanf("%d%d%d", &u, &v, &w);
		G.A[u][v] = w;
	}
	printf("%d\n", Prim(&G, &T));
	for (int i = 1; i <= T.n; i++)
		for (int j = 1; j <= T.n; j++)
			if (T.A[i][j] != 0)
				printf("%d %d %d\n", i, j, T.A[i][j]);
}