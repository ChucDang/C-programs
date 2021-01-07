#include <stdio.h>
#define Maxlength 100
#define MAX 100
int pi[Maxlength];
int mark1[Maxlength];
int count[Maxlength];
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph_A_dinh_dinh;
//Ban đầu gán countx =1 , sau đó khi tìm dc pi[] ngắn hơn thì gán count[v]=count[u]
//con pi bang thi gan count[v]+=count[u]
void Dijkstra(Graph_A_dinh_dinh *G, int x)
{
    int u;
    for (int i = 1; i <= G->n; i++)
    {
        pi[i] = MAX;
        mark1[i] = 0;
    }
    pi[x] = 0;
    count[x] = 1;
    for (int i = 1; i < G->n; i++)
    {
        int min_pi = MAX;
        for (int k = 1; k <= G->n; k++)
            if (mark1[k] == 0 && pi[k] < min_pi)
            {
                min_pi = pi[k];
                u = k;
            }
        mark1[u] = 1;
        for (int v = 1; v <= G->n; v++)
        {
            if (G->A[u][v] != 0 && mark1[v] == 0)
            {
                if (pi[u] + G->A[u][v] < pi[v])
                {
                    pi[v] = pi[u] + G->A[u][v];
                    count[v] = count[u];
                }
                else
                {
                    if (pi[u] + G->A[u][v] == pi[v])
                        count[v] += count[u];
                }
            }
        }
    }
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v, k;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    G.n = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &k);
        G.A[u][v] = k;
        G.A[v][u] = k;
    }
    Dijkstra(&G, 1);
    if (pi[G.n] == Maxlength)
        pi[G.n] = -1;
    printf("%d ", pi[G.n]);
    printf("%d", count[G.n]);
    return 0;
}