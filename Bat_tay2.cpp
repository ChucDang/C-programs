#include "B1706677.h"
int main()
{
    int n, m, a, b, max;
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
    max = get_Index(G, 1);
    for (int i = 2; i <= n; i++)
    {
        int op = get_Index(G, i);
        if (op > max)
        {
            max = op;
        }
    }
    printf("%d", max);
    return 0;
}