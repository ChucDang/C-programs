#include <stdio.h>
int num[100];
int ltm[100];
int min_num[100];
int on_stack[100];
int k = 0,li=0;
typedef struct
{
    int A[100][100];
    int n;
} Graph_A_dinh_dinh;
typedef struct
{
    int e[100];
    int Topindex;
} Stack;
void make_null_Stack(Stack *S)
{
    S->Topindex = 100;
}
int push(Stack *S, int e)
{
    if (S->Topindex == 0)
    {
        return 0;
    }
    else
    {
        S->Topindex--;
        S->e[S->Topindex] = e;
    }
    return 1;
}
int pop(Stack *S)
{
    return S->e[S->Topindex++];
}
Stack S;
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
void add_edge_A_dinh_dinh_co_huong(Graph_A_dinh_dinh *G, int u, int v)
{
    G->A[u][v] = 1;
}
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
void strong_connect(Graph_A_dinh_dinh *G, int x)
{
    num[x] = k;
    min_num[x] = k;
    k++;
    push(&S, x); //Dua x vao stack

    on_stack[x] = 1; //x dang o tren stack
    List list = neighbors_dinh_dinh_co_huong(G, x);
    int i;
    for (i = 0; i < list.size; i++)
    {
        int y = list.arr[i];
        if (num[y] < 0)
        {
            strong_connect(G, y);
            min_num[x] = min(min_num[x], min_num[y]);
        }
        else if (on_stack[y])
            min_num[x] = min(min_num[x], num[y]);
    }
    if (num[x] == min_num[x])
    {
        int w;
        do
        {
            w = pop(&S);
            ltm[li]++;
            on_stack
                [w] = 0;
        } while (w != x);
        li++;
    }
}
int main()
{
    Graph_A_dinh_dinh G;
    int n, m, u, v, p;
    make_null_Stack(&S);
    freopen("dt1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    G.n = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &p);
        add_edge_A_dinh_dinh_co_huong(&G, u, v);
        if (p != 1)
        {
            G.A[v][u] = 1;
        }
    }
    for (v = 1; v <= n; v++)
    {
        num[v] = -1;
        on_stack[v] = 0;
    }
    k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == -1)
            strong_connect(&G, i);
    }
    if (ltm[0] == n)
        printf("OKIE");
    else
        printf("NO");
}
