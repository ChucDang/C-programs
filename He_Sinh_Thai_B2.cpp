#include <stdio.h>
typedef struct
{
    int A[100][100];
    int n;
} Graph;
void init_Graph(Graph *G, int n)
{
    G->n = n;
}
int find_Doi_Thu_Chung(Graph G, int a, int b)
{
    int count = 0;
    for (int i = 1; i <= G.n; i++)
    {
        if ((G.A[a][i] == 1) || (G.A[i][a] == 1))
        {
            if ((G.A[b][i] == 1) || (G.A[i][b] == 1))
            {
                count++;
            }
        }
    }
    return count;
}
void add_edge(Graph *G, int a, int u, int v)
{
    G->A[u][v] = a;
    G->A[v][u] = a;
}
int main()
{
    int n, a, b;
    Graph G;
    scanf("%d", &n);
    init_Graph(&G, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a);
            add_edge(&G, a, i, j);
        }
    }

    scanf("%d", &a);
    scanf("%d", &b);
    n = find_Doi_Thu_Chung(G, a, b);
    printf("%d", n);
    return 0;
}