#include "B1706677.h"
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v, k;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    G.n=n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &k);
        G.A[u][v] = k;
        G.A[v][u] = k;
    }
    Dijkstra(&G, 1);
    if (pi[G.n] > 0)
        printf("%d", pi[G.n]);
    else
    {
        printf("negative cycle");
    }
    return 0;
}
