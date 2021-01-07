#include <stdio.h>
#define grey 0
#define whie 1
#define dark 2
int cycle = 0;
int mark[100];
typedef struct
{
    int A[100][100];
    int n;
} Graph_A_dinh_dinh;
void add_edge_A_dinh_dinh_co_huong(Graph_A_dinh_dinh *G, int u, int v)
{
    G->A[u][v] = 1;
}
typedef struct
{
    int arr[100];
    int size;
} List;
List neighbors_dinh_dinh_co_huong(Graph_A_dinh_dinh *G, int x)
{
    List list;
    list.size = 0;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (G->A[x][i] == 1)
        {
            list.arr[list.size++] = i;
        }
    }
    return list;
}
void chu_Trinh_co_huong(Graph_A_dinh_dinh *G, int x, int p)
{
    mark[x] = grey;
    List list = neighbors_dinh_dinh_co_huong(G, x);
    int i;
    for (i = 0; i < list.size; i++)
    {
        int y = list.arr[i];
//        if (y == p)
//            continue;
        if (mark[y] == grey)
        {
            cycle++;
        }
        if (mark[y] == whie)
        {
            chu_Trinh_co_huong(G, y, x);
        }
    }
    mark[x] = dark;
}
int check_Cycle(Graph_A_dinh_dinh *G)
{
    cycle = 0;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = whie;
    }
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == whie)
            chu_Trinh_co_huong(G, i, 0);
    }
    return cycle;
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    G.n = n;
    int i;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_edge_A_dinh_dinh_co_huong(&G, u, v);
    }
    int temp = check_Cycle(&G);
    if(temp == 2) temp--;
    printf("%d",temp);
}
