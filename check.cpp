#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
//tao danh sach rong
void make_null(List *L)
{
    L->size = 0;
}
//them mot phan tu vao cuoi ds
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}
//lay phan tu tai vi tri i
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}
//tra ve so phan tu cua danh sach
int count_list(List *L)
{
    return L->size;
}
typedef struct
{
    int n;
    List adj[MAX_VERTICES];
} Graph;
//------------------------------------------------------------------------
//khoi tao
void init_graph(Graph *G, int n)
{
    int i;
    G->n = n;
    for (i = 1; i <= n; i++)
        make_null(&G->adj[i]);
}
void add_edge(Graph *G, int x, int y)
{
    push_back(&G->adj[x], y); // y ke voi x
    push_back(&G->adj[y], x); // x ke voi y
}
void add_edge2(Graph *G, int x, int y)
{
    push_back(&G->adj[x], y);
}
//kiem tra y co ke voi x khong
int adjacent(Graph *G, int x, int y)
{
    int j;
    for (j = 1; j <= G->adj[x].size; j++)
        if (element_at(&G->adj[x], j) == y)
            return 1;
    return 0;
}
//bac cua dinh x
int degree(Graph *G, int x)
{
    return G->adj[x].size;
}
//tim cac dinh ke cua dinh x
List neighbors(Graph *G, int x)
{
    int y;
    List list;
    make_null(&list);
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y))
            push_back(&list, y);
    return list;
}
//-----------------------------------------------------------
typedef struct
{
    int data[MAX_ELEMENTS];
    int size;
} Stack;
void make_null_stack(Stack *S)
{
    S->size = 0;
}
void push(Stack *S, int x)
{
    S->data[S->size] = x;
    S->size++;
}
int top(Stack *S)
{
    return S->data[S->size - 1];
}
void pop(Stack *S)
{
    S->size--;
}
int empty(Stack *S)
{
    return S->size == 0;
}
//-----------------------------------------------------------
int num[MAX_VERTICES], min_num[MAX_VERTICES], on_stack[MAX_VERTICES], k;
int ltm[10] = {0}, li = 0;
Stack S;
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
//Duyet do thi bat dau tu dinh
void strong_connect(Graph *G, int x)
{
    num[x] = min_num[x] = k;
    k++;
    push(&S, x);     //Dua x vao stack
    on_stack[x] = 1; //x dang o tren stack
    // Lay cac dinh ke va duyet no
    List list = neighbors(G, x);
    int j;
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
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
            w = top(&S);
            pop(&S);
            ltm[li]++;
            on_stack[w] = 0;
        } while (w != x);
        li++;
    }
}
//-----------------------------------------------------------
int main()
{
    Graph G;
    int i, n, m, e, u, v, q, y;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &q);
        if (q == 2)
        {
            add_edge(&G, u, v);
        }
        else
        {
            add_edge2(&G, u, v);
        }
    }
    for (v = 1; v <= n; v++)
    {
        num[v] = -1;
        on_stack[v] = 0;
    }
    k = 1;
    for (v = 1; v <= n; v++)
    {
        if (num[v] == -1)
            strong_connect(&G, v);
    }
    if (ltm[0] == n)
        printf("OKIE");
    else
        printf("NO");
}