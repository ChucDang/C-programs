#include "B1706677.h"
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    G.n = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_edge_A_dinh_dinh_co_huong(&G, u, v);
    }
    int op = check_CycleHaddock(&G);
    if (op)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
}
