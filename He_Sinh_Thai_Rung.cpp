#include <stdio.h>
typedef struct
{
    int A[100][100];
    int n;
} Graph;
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= G->n; i++)
    {
        for (j = 1; j <= G->n; j++)
        {
            G->A[i][j] = 0;
        }
    }
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
                printf("%d ", i);
                count++;
            }
        }
    }
    return count;
}
void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}
int main()
{
    int n, m, u, v, a, b;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n);
    while (m > 0)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_edge(&G, u, v);
        m--;
    }
    scanf("%d", &a);
    scanf("%d", &b);
    if (find_Doi_Thu_Chung(G, a, b) == 0)
    {
        printf("KHONG CHUNG DOI THU");
    }
    return 0;
}