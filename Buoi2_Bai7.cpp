#include <stdio.h>
typedef struct
{
    int A[100][100];
    int n;
} Graph_A_dinh_dinh;
typedef struct
{
    int arr[100];
    int size;
} List;
List get_L_R(Graph_A_dinh_dinh *G, List *L)
{
    List R;
    R.size = G->n;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        int k;
        for (k = 1; k <= G->n; k++)
        {
            if (G->A[i][k] != 0)
            {
                L->arr[i] = 1;
                R.arr[k] = 1;
            }
        }
    }
    return R;
}
List seperate(Graph_A_dinh_dinh *G, List *L)
{
    List R;
    R = get_L_R(G, L);
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (L->arr[i] * R.arr[i] == 1)
        {
            R.arr[i] = 0;
        }
    }
    return R;
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    G.n = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        G.A[u][v] = 1;
    }
    List L, R;
    R = seperate(&G, &L);
    int check = 0;
    for (int i = 1; i <= n; i++)
    {
        if (L.arr[i] == 1)
        {
            printf("%d ", i);
            check = 1;
        }
    }
    if (check)
    {
        printf("\n");
        for (int j = 1; j <= n; j++)
        {
            if (R.arr[j] == 1)
                printf("%d ", j);
        }
    }
    else
    {
        printf("IMPOSSIBLE");
    }
}
