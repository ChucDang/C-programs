#include <stdio.h>
#define Maxlength 100
typedef int Element_Type;
typedef struct
{
    Element_Type e[Maxlength];
    int Topindex;
} Stack;
void make_null(Stack *S)
{
    S->Topindex = Maxlength;
}
int push(Stack *S, Element_Type e)
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
Element_Type pop(Stack *S)
{
    return S->e[S->Topindex++];
}
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

int parents(Graph *G)
{
    List l;
    l.size = G->n;
    for (int i = 0; i < l.size; i++)
    {
        l.arr[i] = -1;
    }

    Stack S;
    int mark[Maxlength];
    make_null(&S);
    for (int i = 1; i <= G->n; i++)
    {
        mark[i] = 0;
    }
    push(&S, 1);
    l.arr[1] = 0;
    while (S.Topindex != Maxlength)
    {
        int x = pop(&S);
        if (mark[x] != 0)
            continue;
        mark[x] = 1;
        List list = neighbors(G, x);
        for (int i = 0; i < list.size; i++)
        {
            int y = list.arr[i];
            push(&S, y);
            if (l.arr[y] == -1)
            {
                l.arr[y] = x;
            }
        }
    }
    for (int i = 1; i <= G->n; i++)
    {
        if (mark[i] == 0)
        {
            return 0;
        }
    }
    return 1;
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
    if (parents(&G) == 1)
    {
        printf("DUOC");
    }
    else
    {
        printf("KHONG");
    }
}