#include "B1706677.h"
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