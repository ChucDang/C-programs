#include <stdio.h>
#define Maxlength 100
int pi[Maxlength];
int p[Maxlength];
int mark[Maxlength];
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph_A_dinh_dinh;
void init_graph_A_dinh_dinh(Graph_A_dinh_dinh *G, int n)
{
    G->n = n;
    for (int i = 1; i <= G->n; i++)
    {
        for (int j = 1; j <= G->n; j++)
        {
            G->A[i][j] = 0;
        }
    }
}
void Dijkstra(Graph_A_dinh_dinh *G, int x)
{
    int u, v;
    for (int i = 1; i <= G->n; i++)
    {
        pi[i] = Maxlength;
        mark[i] = 0;
    }
    pi[x] = 0;
    p[x] = -1;
    for (int i = 1; i < G->n; i++)
    {
        int min_pi = Maxlength;
        for (int j = 1; j <= G->n; j++)
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                u = j;
            }
        mark[u] = 1;
        for (v = 1; v <= G->n; v++)
            if (G->A[u][v] != 0 && mark[v] == 0)
                if (pi[u] + G->A[u][v] < pi[v])
                {
                    pi[v] = pi[u] + G->A[u][v];
                    p[v] = u;
                }
    }
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v, k;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    init_graph_A_dinh_dinh(&G, n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &k);
        G.A[u][v] = k;
        G.A[v][u] = k;
    }
    Dijkstra(&G, 1);
    if (pi[G.n] == Maxlength)
        pi[G.n] = -1;
    printf("%d", pi[G.n]);
    return 0;
}