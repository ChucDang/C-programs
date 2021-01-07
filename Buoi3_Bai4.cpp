#include "stdio.h"
#define Maxlength 100
int pi[Maxlength];
int p[Maxlength];
int mark[Maxlength];
#define MAX 1000
int MT[100][100];
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph_A_dinh_dinh;
//index luc nay dong vai tro la duong di, nen init ma MAX, khong phai 0
void init_graph_A_dinh_dinh(Graph_A_dinh_dinh *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= G->n; i++)
    {
        for (j = 1; j <= G->n; j++)
        {
            if (i == j)
            {
                G->A[i][j] = 0;
            }
            else
            {
                G->A[i][j] = MAX;
            }
        }
    }
}
// Dijstra nay khac cho d(x)= MT[1][1]
void Dijkstra(Graph_A_dinh_dinh *G, int x)
{
    int u, v;
    for (int i = 1; i <= G->n; i++)
    {
        pi[i] = MAX;
        p[i] = 0;
    }
    pi[x] = MT[1][1];
    p[x] = -1;
    for (int i = 1; i < G->n; i++)
    {
        int min_pi = MAX;
        for (int k = 1; k <= G->n; k++)
            if (mark[k] == 0 && pi[k] < min_pi)
            {
                min_pi = pi[k];
                u = k;
            }
        mark[u] = 1;
        for (v = 1; v <= G->n; v++)
            if (G->A[u][v] != 0 && mark[v] == 0)
                if (pi[u] + G->A[u][v] < pi[v])
                {
                    pi[v] = pi[u] + G->A[u][v];
                    p[v] = u;
                }
    }
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, N, M;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    //Doc va gan vo ma tran
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &MT[i][j]);
        }
    }
    n = N * M;
    //Khoi tao do thi co N*M dinh
    init_graph_A_dinh_dinh(&G, n);
    //Chuyen du lieu trong ma tran sang do thi G;
    //len, xuong, trai, phai
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    //ii và jj la toa do i, j trong ma tran MT[][]
    int ii, jj, i1, j1;
    for (int u = 1; u <= n; u++)
    {
        ii = (u - 1) / M + 1;
        jj = (u - 1) % M + 1;
        for (int temp = 0; temp < 4; temp++)
        {
            i1 = ii + di[temp];
            j1 = jj + dj[temp];
            if (i1 > 0 && i1 <= N && j1 > 0 && j1 <= M)
            {
                G.A[u][(i1 - 1) * M + j1] = MT[i1][j1];
            }
        }
    }
    Dijkstra(&G, 1);
    printf("%d", pi[n]);
    return 0;
}
