#include "B1706677.h"
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    init_graph_A_dinh_dinh(&G, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_edge_A_dinh_dinh_vo_huong(&G, u, v);
    }
    if (check_Cycle(&G) == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}