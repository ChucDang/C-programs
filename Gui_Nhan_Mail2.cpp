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
int get_So_Lan(Graph G, int a)
{
    int count = 0;
    for (int i = 1; i <= G.n; i++)
    {
        count += G.edges[a][i].index;
    }
    return count;
}
void add_index(Graph *G, int a, int b)
{
    if (a != b)
    {
        G->edges[a][b].index++;
    }
}
int main()
{
    int n, u, v, m, countmax = 0, sendmax = 0;
    Graph G;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    init_Graph(&G, n);
    for (int j = 1; j <= m; j++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add_index(&G, u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        int op = get_So_Lan(G, i);
        if (op > countmax)
        {
            countmax = op;
            sendmax = i;
        }
    }
    printf("%d has sent %d email(s).", sendmax, countmax);
    return 0;
}