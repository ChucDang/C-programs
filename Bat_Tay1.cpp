#include "B1706677.h"
int main()
{
    int n, m, a, b;
    Graph_Edge G;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    init_Graph_Edge(&G, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        add_edge_Edge(&G, i, a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", get_Index(G, i));
    }
    return 0;
}