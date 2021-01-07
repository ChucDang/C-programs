#include "B1706677.h"
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v;
    int mark[Maxlength];
    List parent;
    parent.size = n;
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
    for (int i = 1; i <= n; i++)
    {
        mark[i] = 0;
        parent.arr[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] != 1)
            DFS_DeQui(&G, i, mark, &parent);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", i, parent.arr[i]);
    }
}