#include "B1706677.h"
int d[100];
int main()
{
    Graph_A_dinh_dinh G;
    int n, u;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    G.n = n + 2;
    //d[i] la thoi gian hoan thanh cong viec
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
        do
        {
            scanf("%d", &u);
            if (u > 0)
            {
                //co cung huong tu u toi i
                G.A[u][i] = 1;
            }
        } while (u > 0);
    }
    //Tinh bac am duong cua i;
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
    List L;
    topo_sort(&G, &L);
    int t[100];
    //thay vi cho i chay tu 1 toi L.size -1
    for (int i = 2; i <= L.size; i++)
    {
        int u = L.arr[i - 1];
        t[u] = -1;
        for (int j = 1; j <= G.n; j++)
        {
            if (G.A[j][u] != 0)
            {
                t[u] = max(t[u], t[j] + d[j]);
            }
        }
    }
    int T[100];
    T[n + 2] = t[n + 2];
    for (int i = L.size - 1; i >= 1; i--)
    {
        int u = L.arr[i - 1];
        T[u] = 1000;
        for (int j = 1; j <= G.n; j++)
        {
            if (G.A[u][j] != 0)
            {
                T[u] = min(T[u], T[j] - d[u]);
            }
        }
    }
    //t la time tre nhat, T la time som nhat
    //cong viec thu W, thoi gian bat dau thuc hien la S, co tre hay khong?
    int W, S;
    if (t[W] <= S && T[W] >= S)
        printf("YES");
    else
        printf("NO");
    //In ra danh sach cong viec then chot, tuc t = T;
    for (int i = 1; i <= n + 2; i++)
        if (t[i] == T[i])
            printf("%d\n", i);
    //In ra thoi gian som nhat co the hoan thanh.
    printf("%d\n", t[n + 2]);
    for (int i = 1; i <= G.n; i++)
    {
        printf("%d-%d\n", t[i], T[i]);
    }
}
