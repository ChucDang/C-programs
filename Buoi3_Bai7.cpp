#include "B1706677.h"
//MAX va Maxlength chi nen cho so duoi 1000
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v, k;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    G.n = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &k);
        G.A[u][v] = k;
    }
    Floyd_Warshall(&G);
    for (int e = 1; e <= n; e++)
        for (int f = 1; f <= n; f++)
        {
            if (pi1[e][f] >= MAX - 100)
                printf("%d -> %d: oo\n", e, f);
            else
                printf("%d -> %d: %d\n", e, f, pi1[e][f]);
        }
    return 0;
}