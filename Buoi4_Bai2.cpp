#include <stdio.h>
#define Maxlength 100
typedef struct
{
    int arr[Maxlength];
    int size;
} List;
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph_A_dinh_dinh;
int k;
int rank[Maxlength];
//Khong ap dung cho vo huong
//Giong giai thuat ranking ben thu vien. nhung dem k ra local và in dinh
void ranking(Graph_A_dinh_dinh *G)
{
    int d[Maxlength];
    //for nếu G->A[x][u] tồn tại thì du++
    for (int i = 1; i <= G->n; i++) d[i]=0;
    for (int i = 1; i <= G->n; i++)
        for (int j = 1; j <= G->n; j++)
            if (G->A[i][j] != 0)
                d[j]++;
    List S1, S2;
    S1.size = 0;
    for (int u = 1; u <= G->n; u++)
        if (d[u] == 0)
            S1.arr[S1.size++] = u;
    k = 0;
    while (S1.size > 0)
    {
        S2.size = 0;
        for (int i = 0; i < S1.size; i++)
        {
            int u = S1.arr[i];
            rank[u] = k;
            for (int v = 1; v <= G->n; v++)
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (d[v] == 0)
                        S2.arr[S2.size++] = v;
                }
        }
        S1.size = 0;
        for (int i = 0; i < S2.size; i++)
        {
            S1.arr[S1.size++] = S2.arr[i];
        }
        k++;
    }
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    G.n = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        G.A[u][v] = 1;
    }
    ranking(&G);
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (rank[j] == i)
            {
                printf("%d ", j);
            }
        }
    }
    return 0;
}
