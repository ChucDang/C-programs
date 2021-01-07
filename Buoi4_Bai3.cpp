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
int k = 0;
int rank[Maxlength];
//Khong ap dung cho vo huong
//Giong giai thuat ranking ben thu vien. nhung dem k ra local
void ranking(Graph_A_dinh_dinh *G)
{
    int d[Maxlength];
    for (int j = 1; j <= G->n; j++)
                d[j]=0;
    for (int i = 1; i <= G->n; i++)
        for (int j = 1; j <= G->n; j++)
            if (G->A[i][j] != 0)
                d[j]++;
    List S1, S2;
    S1.size = 0;
    for (int u = 1; u <= G->n; u++)
        if (d[u] == 0)
            S1.arr[S1.size++] = u;
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
    //u muon nhieu keo hon v nen chen vao v u nhe
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        G.A[v][u] = 1;
    }
    ranking(&G);
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        //do trong ham gan rank=k , k =0 nen so keo phai +1
        printf("%d\n", rank[i] + 1);
        s += rank[i] + 1;
    }
    printf("%d\n", s);
    return 0;
}
