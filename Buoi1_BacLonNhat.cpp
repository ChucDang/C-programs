#include "B1706677.h"

int main()
{
    Graph_A G;
    int n, m, u, v, w, e;
    int degmax, dinh;
    List list;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    init_graph_A(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_edge_dinh_cung(&G, e, u, v);
    }
    list = neighbors_dinh_cung(&G, 1);
    degmax = list.size;
    for (w = 1; w <= n; w++)
    {
        list = neighbors_dinh_cung(&G, w);
        int temp = list.size;
        if (temp > degmax)
        {
            degmax = temp;
            dinh = w;
        }
    }
    printf("%d %d\n", dinh, degmax);
}
