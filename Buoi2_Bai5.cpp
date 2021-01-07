#include <stdio.h>
#define Maxlength 100
#define white 0
#define grey 1
#define black 2
typedef int Element_Type;
int cycle;
int mark[Maxlength];
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph;
typedef struct
{
    int arr[Maxlength];
    int size;
} List;

void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= G->n; i++)
    {
        for (j = 1; j <= G->n; j++)
        {
            G->A[i][j] = 0;
        }
    }
}
void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}
List neighbors(Graph *G, int x)
{
    List list;
    list.size = 0;
    for (int i = 1; i <= G->n; i++)
    {
        if (G->A[x][i] == 1)
        {
            list.arr[list.size++] = i;
        }
    }
    return list;
}
//Cần phải kiểm tra xem con của x có phải là p không.
void DFS_DeQui(Graph *G, int x, int p)
{
    mark[x] = grey;
    List list = neighbors(G, x);
    for (int i = 0; i < list.size; i++)
    {
        int y = list.arr[i];
        if (y == p)
            continue;
        if (mark[y] == grey)
        {
            cycle = 1;
            return;
        }
        if (mark[y] == white)
        {
            DFS_DeQui(G, y, x);
        }
    }
    mark[x] = black;
}
int check_Cycle(Graph *G)
{
    cycle = 0;
    for (int i = 1; i <= G->n; i++)
    {
        mark[i] = white;
    }
    for (int i = 1; i <= G->n; i++)
    {
        if (mark[i] == white)
            DFS_DeQui(G, i, 0);
    }
    return cycle;
}

int main()
{
    Graph G;
    int n, m, u, v;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    init_graph(&G, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_edge(&G, u, v);
    }

    if (check_Cycle(&G) == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}