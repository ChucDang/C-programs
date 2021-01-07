#include "B1706677.h"
int d[Maxlength];
int main()
{
    Graph_A_dinh_dinh G;
    List L;
    int n, y, x, u, j, v, W, S;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    G.n = n + 2;
    for (u = 1; u <= n; u++)
    {
        scanf("%d", &d[u]);
        do
        {
            scanf("%d", &x);
            if (x > 0)
                G.A[x][u] = 1;
        } while (x > 0);
    }
    scanf("%d%d", &W, &S);
    for (int i = 1; i <= n; i++)
    {
        int deg_neg = 0, deg_pos = 0;
        for (int j = 1; j <= n; j++)
        {
            if (G.A[i][j] > 0)
                deg_pos++;
            if (G.A[j][i] > 0)
                deg_neg++;
        }
        //neu dinh i khong co cung nao toi thi gan nut bat dau (n+1) toi i;
        if (deg_neg == 0)
            G.A[n + 1][i] = 1;
        //neu dinh i khong co cung nao ra thi gan cung tu i den nut ket thuc (n+2);
        if (deg_pos == 0)
            G.A[i][n + 2] = 1;
    }
    topo_sort(&G, &L);
    int t[100];
    for (j = 2; j <= L.size; j++)
    {
        int u = L.arr[j - 1];
        t[u] = -1;
        for (v = 1; v <= G.n; v++)
            if (G.A[v][u] != 0)
                t[u] = max(t[u], t[v] + d[v]);
    }
    int T[100];
    T[n + 2] = t[n + 2];
    for (j = L.size - 1; j >= 1; j--)
    {
        int u = L.arr[j - 1];
        T[u] = 1000;
        for (v = 1; v <= G.n; v++)
            if (G.A[u][v] != 0)
                T[u] = min(T[u], T[v] - d[u]);
    }
    //t la time tre nhat, T la time som nhat
    if (t[W] <= S && T[W] >= S)
        printf("YES");
    else
        printf("NO");
    return 0;
}