#include <stdio.h>
typedef struct
{
    int index;
} Edge;
typedef struct
{
    Edge edges[100][100];
    int n;
} Graph;
void init_Graph(Graph *G, int n)
{
    G->n = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            G->edges[i][j].index = 0;
        }
    }
}
int get_So_Lan(Graph G, int a, int b)
{
    return G.edges[a][b].index;
}
void add_index(Graph *G, int a, int b, int index)
{
    if (a != b)
    {
        G->edges[a][b].index = index;
    }
}
int main()
{
    int n, index, max, nhan = 0;
    Graph G;
    scanf("%d", &n);
    init_Graph(&G, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &index);
            add_index(&G, i, j, index);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            count += get_So_Lan(G, j, i);
        }
        if (count > max)
        {
            max = count;
            nhan = i;
        }
    }
    printf("%d has received %d email(s).", nhan, max);
    return 0;
}