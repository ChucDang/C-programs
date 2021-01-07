#include <stdio.h>
typedef struct
{
	int arr[100];
	int size;
} List;
typedef struct
{
	int A[100][100];
	int n;
} Graph_A_dinh_dinh;
int rank[100];
//Khong ap dung cho vo huong
void ranking(Graph_A_dinh_dinh *G)
{
	int d[100];
	for (int i = 1; i <= G->n; i++){
		
	}
		for (int j = 1; j <= G->n; j++)
			if (G->A[i][j] != 0)
				d[j]++;
	List S1, S2;
	S1.size = 0;
	for (int u = 1; u <= G->n; u++)
		if (d[u] == 0)
			S1.arr[S1.size++] = u;
	int k = 0;
	while (S1.size > 0)
	{
		S2.size = 0;
		for (int i = 0; i < S1.size; i++)
		{
			int u = S1.arr[i];
			rank[u] = k;
			for (int v = 1; v <= G->n; v++)
				if (G->A[u][v] != 0)
				{
					d[v]--;
					if (d[v] == 0)
						S2.arr[S2.size++] = v;
				}
		}
		S1.size = 0;
		for (int i = 0; i < S2.size; i++)
		{
			S1.arr[S1.size++] = S2.arr[i];
		}
		k++;
	}
}
int main()
{
	Graph_A_dinh_dinh G;
	int n, m, u, v;
	freopen("dt1.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	G.n = n;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		G.A[u][v] = 1;
	}
	ranking(&G);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", rank[i]);
	}
	return 0;
}
