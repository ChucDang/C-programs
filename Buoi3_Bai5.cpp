#include "B1706677.h"
int main()
{
    Graph_Edge G;
    int n, m, v, u, k;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    G.n = n;
    G.m = m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &k);
        G.edges[i].a = u;
        G.edges[i].b = v;
        G.edges[i].index = k;
    }
    BellmanFord(&G, 1);
    for (int e = 1; e <= n; e++)
    {
        printf("pi[%d] = %d, p[%d] = %d\n", e, pi[e], e, p[e]);
    }
}