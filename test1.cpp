#include <stdio.h>
int d[100];
#define Maxlength 100
typedef struct
{
    int Elements[Maxlength];
    int Front, Rear;
} Queue;
int empty(Queue *Q)
{
    return Q->Front > Q->Rear;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph_A_dinh_dinh;
int degree(Graph_A_dinh_dinh *G, int x)
{
    int deg = 0;
    for (int i = 1; i <= G->n + 2; i++)
        deg += G->A[i][x];
    return deg;
}
void make_Null_Queue(Queue *Q)
{
    (*Q).Front = 0;
    (*Q).Rear = -1;
}
//Đưa vào thì đuôi tăng 1 rui mới gán x;
void en_Queue(Queue *Q, int X)
{
    (*Q).Elements[++(*Q).Rear] = X;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
typedef struct
{
    int arr[Maxlength];
    int size;
} List;
int de_Queue(Queue *Q)
{
    return Q->Elements[Q->Front++];
}
void topo_sort(Graph_A_dinh_dinh *G, List *L)
{
    int deg[100];
    Queue Q;
    make_Null_Queue(&Q);
    L->size = 0;
    for (int i = 1; i <= G->n; i++)
    {
        deg[i] = degree(G, i);
        if (deg[i] == 0)
            en_Queue(&Q, i);
    }

    while (!empty(&Q))
    {
        int u = de_Queue(&Q);
        L->arr[L->size++] = u;
        for (int i = 1; i <= G->n; i++)
            if (G->A[u][i] != 0)
            {
                deg[i]--;
                if (deg[i] == 0)
                    en_Queue(&Q, i);
            }
    }
}

int main()
{
    Graph_A_dinh_dinh G;
    int n, u;
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    G.n = n + 2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
        do
        {
            scanf("%d", &u);
            if (u > 0)
            {
                //co cung huong tu u toi i
                G.A[u][i] = 1;
            }
        } while (u > 0);
    }
    // Tinh bac am duong cua i;
    for (int i = 1; i <= n; i++)
    {
        int deg_neg = 0, deg_pos = 0;
        for (int j = 1; j <= n; j++)
        {
            if (G.A[i][j] > 0)
                deg_pos++;
            if (G.A[j][i] > 0)
                deg_neg++;
        }
        //neu dinh i khong co cung nao toi thi gan nut bat dau (n+1) toi i;
        if (deg_neg == 0)
            G.A[n + 1][i] = 1;
        //neu dinh i khong co cung nao ra thi gan cung tu i den nut ket thuc (n+2);
        if (deg_pos == 0)
            G.A[i][n + 2] = 1;
    }
    List L;
    topo_sort(&G, &L);
    int t[100];
    t[n + 1] = 0;
    for (int i = 2; i <= L.size; i++)
    {
        int u = L.arr[i - 1];
        t[u] = -1;
        for (int j = 1; j <= G.n; j++)
        {
            if (G.A[j][u] != 0)
            {
                t[u] = max(t[u], t[j] + d[j]);
            }
        }
    }
    int T[100];
    T[n + 2] = t[n + 2];
    for (int i = L.size - 1; i >= 1; i--)
    {
        int u = L.arr[i - 1];
        T[u] = 1000;
        for (int j = 1; j <= G.n; j++)
        {
            if (G.A[u][j] != 0)
            {
                T[u] = min(T[u], T[j] - d[u]);
            }
        }
    }
    printf("%d\n", t[n + 2]);
    for (int i = 1; i <= G.n; i++)
    {
        printf("%d-%d\n", t[i], T[i]);
    }
}
