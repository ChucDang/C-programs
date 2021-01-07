#include <stdio.h>
#define Maxlength 100
typedef int Element_Type;
#define whie 0
#define grey 1
#define dark 2
int k;
typedef struct
{
    int arr[Maxlength];
    int size;
} List;
// ------------------------Graph_Edge-------------------------------
typedef struct
{
    int a, b, index;
} Edge;
typedef struct
{
    Edge edges[100];
    int n, m;
} Graph_Edge;
void init_Graph_Edge(Graph_Edge *G, int n)
{
    G->n = n;
    G->m = 0;
}
void add_edge_Edge(Graph_Edge *G, int a, int b, int index)
{
    if (a != b)
    {
        G->edges[G->m].a = a;
        G->edges[G->m].b = b;
        G->edges[G->m].index = index;
        G->m++;
    }
}
List neighbor_edge(Graph_Edge *G, int a)
{
    List list;
    list.size = 0;
    int i;
    for (i = 1; i <= G->m; i++)
    {
        if ((G->edges[i].a == a) || (G->edges[i].b == a))
        {
            list.arr[list.size++] = 1;
        }
    }
    return list;
}
void add_Edge(Graph_Edge *G, int e, int a, int b)
{
    if (a != b)
    {
        G->edges[e].a = a;
        G->edges[e].b = b;
        G->m++;
    }
}

// --------------------------Queue---------------------------------
typedef struct
{
    Element_Type Elements[Maxlength];
    int Front, Rear;
} Queue;
void make_Null_Queue(Queue *Q)
{
    (*Q).Front = 0;
    (*Q).Rear = -1;
}

void en_Queue(Queue *Q, int X)
{
    (*Q).Elements[++(*Q).Rear] = X;
}
Element_Type de_Queue(Queue *Q)
{
    return Q->Elements[Q->Front++];
}
// ----------------------------Stack------------------------------
typedef struct
{
    Element_Type e[Maxlength];
    int Topindex;
} Stack;
void make_null_Stack(Stack *S)
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
    int n, m;
} Graph_A_dinh_cung;
typedef struct
{
    int A[Maxlength][Maxlength];
    int n;
} Graph_A_dinh_dinh;
// ----------------------add_Edge-------------------------
void add_edge_dinh_cung(Graph_A_dinh_cung *G, int e, int u, int v)
{
    G->A[u][e] = 1;
    G->A[v][e] = 1;
}
void add_edge_A_dinh_dinh_co_huong(Graph_A_dinh_dinh *G, int u, int v)
{
    G->A[u][v] = 1;
}
void add_edge_A_dinh_dinh_vo_huong(Graph_A_dinh_dinh *G, int u, int v)
{
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}
// ----------------------------neighbors-------------------------
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
int degree(Graph_A_dinh_dinh *G, int x)
{
    int deg = 0;
    int i;
    for (i = 1; i <= G->n + 2; i++)
        deg += G->A[i][x];
    return deg;
}
List neighbors_dinh_dinh_vo_huong(Graph_A_dinh_dinh *G, int x)
{
    List list;
    list.size = 0;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (G->A[x][i] == 1 || G->A[i][x] == 1)
        {
            list.arr[list.size++] = i;
        }
    }
    return list;
}
List neighbors_dinh_cung(Graph_A_dinh_cung *G, int x)
{
    List list;
    list.size = 0;
    int i;
    for (i = 1; i < G->m; i++)
    {
        if (G->A[x][i] == 1)
        {
            list.arr[list.size++] = i;
        }
    }
    return list;
}
// --------------------------------DFS--------------------------------------
void BFS_dinh_dinh_co_huong(Graph_A_dinh_dinh *G)
{
    Queue Q;
    int mark[Maxlength];
    for (k = 1; k <= G->n; k++)
        mark[k] = 0;
    make_Null_Queue(&Q);
    en_Queue(&Q, 1);
    printf("%d\n", 1);
    mark
        [1] = 1;
A:
    while (Q.Front != -1)
    {
        Element_Type x = de_Queue(&Q);
        List list = neighbors_dinh_dinh_co_huong(G, x);
        int k;
        for (k = 0; k < list.size; k++)
        {
            int y = list.arr[k];
            if (mark
                    [y] == 0)
            {
                printf("%d\n", y);
                mark
                    [y] = 1;
                en_Queue(&Q, y);
            }
        }
    }
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] != 1)
        {
            en_Queue(&Q, i);
            mark[i] = 1;
            printf("%d\n", i);
            goto A;
        }
    }
}
void BFS_dinh_dinh_vo_huong(Graph_A_dinh_dinh *G)
{
    Queue Q;
    int mark
        [Maxlength];
    int k;
    for (k = 1; k <= G->n; k++)
        mark[k] = 0;
    make_Null_Queue(&Q);
    en_Queue(&Q, 1);
    printf("%d %d\n", 1, 0);
    mark
        [1] = 1;
A:
    while (Q.Front != -1)
    {
        Element_Type x = de_Queue(&Q);
        List list = neighbors_dinh_dinh_vo_huong(G, x);
        int k;
        for (k = 0; k < list.size; k++)
        {
            int y = list.arr[k];
            if (mark
                    [y] == 0)
            {
                printf("%d %d\n", y, x);
                mark
                    [y] = 1;
                en_Queue(&Q, y);
            }
        }
    }
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (mark
                [i] != 1)
        {
            en_Queue(&Q, i);
            mark
                [i] = 1;
            printf("%d %d\n", i, 0);
            goto A;
        }
    }
}
List BFS_dinh_dinh_vo_huong_co_thu_tu(Graph_A_dinh_dinh *G)
{
    int mark[Maxlength];
    int k;
    for (k = 1; k <= G->n; k++)
        mark[k] = 0;
    Queue Q;
    make_Null_Queue(&Q);
    List parent;
    parent.size = G->n;
    en_Queue(&Q, 1);
    mark
        [1] = 1;
    parent.arr[1] = 0;
A:
    while (Q.Front != -1)
    {
        Element_Type x = de_Queue(&Q);
        List list = neighbors_dinh_dinh_vo_huong(G, x);
        int k;
        for (k = 0; k < list.size; k++)
        {
            int y = list.arr[k];
            if (mark[y] == 0)
            {
                parent.arr[y] = x;
                mark
                    [y] = 1;
                en_Queue(&Q, y);
            }
        }
    }
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] != 1)
        {
            en_Queue(&Q, i);
            mark
                [i] = 1;
            parent.arr[i] = 0;
            goto A;
        }
    }
    return parent;
}
void BFS_dinh_dinh_co_huong_in_cha(Graph_A_dinh_dinh *G)
{
    Queue Q;
    int mark[Maxlength];
    int k;
    for (k = 1; k <= G->n; k++)
        mark[k] = 0;
    make_Null_Queue(&Q);
    en_Queue(&Q, 1);
    printf("%d %d\n", 1, 0);
    mark[1] = 1;
A:
    while (Q.Front != -1)
    {
        Element_Type x = de_Queue(&Q);
        List list = neighbors_dinh_dinh_co_huong(G, x);
        int k;
        for (k = 0; k < list.size; k++)
        {
            int y = list.arr[k];
            if (mark[y] == 0)
            {
                printf("%d %d\n", y, x);
                mark[y] = 1;
                en_Queue(&Q, y);
            }
        }
    }
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] != 1)
        {
            en_Queue(&Q, i);
            mark[i] = 1;
            printf("%d %d\n", i, 0);
            goto A;
        }
    }
}
List BFS_dinh_dinh_co_huong_in_cha_co_thu_tu(Graph_A_dinh_dinh *G)
{
    Queue Q;
    List parent;
    parent.size = G->n;
    int mark[Maxlength];
    int k;
    for (k = 1; k <= G->n; k++)
        mark[k] = 0;
    make_Null_Queue(&Q);
    en_Queue(&Q, 1);
    mark[1] = 1;
    parent.arr[1] = 0;
A:
    while (Q.Front != -1)
    {
        Element_Type x = de_Queue(&Q);
        List list = neighbors_dinh_dinh_co_huong(G, x);
        int k;
        for (k = 0; k < list.size; k++)
        {
            int y = list.arr[k];
            if (mark[y] == 0)
            {
                parent.arr[y] = x;
                mark[y] = 1;
                en_Queue(&Q, y);
            }
        }
    }
    int i;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] != 1)
        {
            en_Queue(&Q, i);
            mark[i] = 1;
            parent.arr[i] = 0;
            goto A;
        }
    }
    return parent;
}
// ----------------------------DFS--------------------------
List DFS_vo_huong(Graph_A_dinh_dinh *G)
{
    Stack S;
    List list;
    list.size = G->n;
    int mark[Maxlength];
    make_null_Stack(&S);
    int i;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = 0;
    }
    push(&S, 1);
    list.arr[1] = 0;
A:
    while (S.Topindex != Maxlength)
    {
        int x = pop(&S);
        printf("%d", x);
        break;
        if (mark[x] != 0)
            continue;
        mark[x] = 1;
        List list = neighbors_dinh_dinh_vo_huong(G, x);
        int i;
        for (i = 0; i < list.size; i++)
        {
            int y = list.arr[i];
            if (mark[y] == 0)
            {
                list.arr[y] = x;
                push(&S, y);
            }
        }
    }
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == 0)
        {
            list.arr[i] = 0;
            push(&S, i);
            goto A;
        }
    }
    return list;
}
// ---------------------------De_Qui--------------------------------
void DFS_DeQui(Graph_A_dinh_dinh *G, int x, int mark[], List *parent)
{
    if (mark[x] != 0)
    {
        return;
    }
    else
    {
        mark[x] = 1;
        List list = neighbors_dinh_dinh_vo_huong(G, x);
        int i;
        for (i = 0; i < list.size; i++)
        {
            parent->arr[list.arr[i]] = x;
            if (mark[i] == 0)
                DFS_DeQui(G, list.arr[i], mark, parent);
        }
    }
}
// ---------------------------Chu_Trinh-----------------------------
// Kiem tra lien thong manh
int mark[Maxlength];
int cycle;
void chu_Trinh_co_huong(Graph_A_dinh_dinh *G, int x, int p)
{
    mark[x] = grey;
    List list = neighbors_dinh_dinh_co_huong(G, x);
    int i;
    for (i = 0; i < list.size; i++)
    {
        int y = list.arr[i];
        if (y == p)
            continue;
        if (mark[y] == grey)
        {
            cycle = 1;
            return;
        }
        if (mark[y] == whie)
        {
            chu_Trinh_co_huong(G, y, x);
        }
    }
    mark[x] = dark;
}
int check_Cycle(Graph_A_dinh_dinh *G)
{
    cycle = 0;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = whie;
    }
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == whie)
            chu_Trinh_co_huong(G, i, 0);
    }
    return cycle;
}
// ----------------------Thuyen Truong Haddock-----------------------
//Haddock la khong ton tai chu trinh
void chu_TrinhHaddock(Graph_A_dinh_dinh *G, int x)
{
    mark[x] = grey;
    List list = neighbors_dinh_dinh_co_huong(G, x);
    int i;
    for (i = 0; i < list.size; i++)
    {
        int y = list.arr[i];
        if (mark[y] == grey)
        {
            cycle++;
            return;
        }
        if (mark[y] == whie)
        {
            chu_TrinhHaddock(G, y);
        }
    }
    mark[x] = dark;
}
int check_CycleHaddock(Graph_A_dinh_dinh *G)
{
    cycle = 0;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = whie;
    }
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == whie)
            chu_TrinhHaddock(G, i);
    }
    return cycle;
}
// --------------------- Phan chia doi bong-------------------------
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
            L->arr[i] = 0;
        }
    }
    return R;
}
// --------------------------Lien thong manh----------------------------
int num[Maxlength], min_num[Maxlength], on_stack[Maxlength];
int ltm[10], li = 0;
Stack S;
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
//Duyet do thi bat dau tu dinh
void strong_connect(Graph_A_dinh_dinh *G, int x)
{
    //Bam dau gan mun=min_num=so thu tu xet;
    num[x] = min_num[x] = k;
    k++;
    push(&S, x); //Dua x vao stack

    on_stack[x] = 1; //x dang o tren stack
    List list = neighbors_dinh_dinh_co_huong(G, x);
    int k;
    for (k = 0; k < list.size; k++)
    {
        int y = list.arr[k];
        if (num[y] < 0)
        {
            strong_connect(G, y);
            min_num[x] = min(min_num[x], min_num[y]);
        }
        else if (on_stack[y])
            min_num[x] = min(min_num[x], num[y]);
    }
    //neu con ton tai num=min_num thi pop stack den khi gap x;
    //ltm[0]=n tuc la chi co 1 thanh phan lien thong manh.
    //li la so thanh phan lien thong manh
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
// ---------------------Tìm đường đi ngắn nhất Dikkstra-------------------------
int pi[Maxlength];
int p[Maxlength];
int mark1[Maxlength];
#define MAX 1000
//neu do dai duong di tu x den n = MAX thi gan p[n]=-1;
void Dijkstra(Graph_A_dinh_dinh *G, int x)
{
    int u, v;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        pi[i] = MAX;
        p[i] = 0;
    }
    pi[x] = 0;
    p[x] = -1;
    for (i = 1; i < G->n; i++)
    {
        int min_pi = MAX;
        int k;
        for (k = 1; k <= G->n; k++)
            if (mark1[k] == 0 && pi[k] < min_pi)
            {
                min_pi = pi[k];
                u = k;
            }
        mark1[u] = 1;
        for (v = 1; v <= G->n; v++)
            if (G->A[u][v] != 0 && mark1[v] == 0)
                if (pi[u] + G->A[u][v] < pi[v])
                {
                    pi[v] = pi[u] + G->A[u][v];
                    p[v] = u;
                }
    }
}
// Dijkstra nang cao tinh so duong di ngan nhat tu mot dinh;
//neu do dai duong di tu x den n = MAX thi gan p[n]=-1;
int count[Maxlength];
void Dijkstra_count(Graph_A_dinh_dinh *G, int x)
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
// ---------------------Bellman - Ford pi and pi-----------------------------
//  Tim duong di ngan nhat tu mot dinh den tat ca cac dinh con lai
void BellmanFord(Graph_Edge *G, int s)
{
    int i;
    for (i = 1; i <= G->n; i++)
    {
        pi[i] = MAX;
    }
    pi[s] = 0;
    p[s] = -1;
    for (i = 1; i <= G->n; i++)
    {
        int k;
        for (k = 1; k <= G->m; k++)
        {
            int u = G->edges[k].a;
            int v = G->edges[k].b;
            int w = G->edges[k].index;
            if (pi[u] + w < pi[v])
            {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}
//Kiem tra chu trinh am thong qua giai thuat Bellman - Ford
int checknegativecycle(Graph_Edge *G)
{
    int k;
    for (k = 1; k <= G->m; k++)
    {
        int u = G->edges[k].a;
        int v = G->edges[k].b;
        int w = G->edges[k].index;
        if (pi[u] + w < pi[v])
        {
            return 1;
            break;
        }
    }
    return 0;
}
// ---------------------Floyd Warshall----------------------
// Tim duong di ngan nhat cua tat ca cac cap dinh trong do thi G
int pi1[Maxlength][Maxlength];
int next[Maxlength][Maxlength];
void Floyd_Warshall(Graph_A_dinh_dinh *G)
{
    int u, v, k;
    //Khoi tao do dai i -> i =0 va cac do dai con lai la vo cung lon
    //Next[u][v] la dinh ke tiep cua u
    for (u = 1; u <= G->n; u++)
    {
        pi1[u][u] = 0;
        for (v = 1; v <= G->n; v++)
        {
            if (u == v)
                continue;
            pi1[u][v] = MAX;
            next[u][v] = -1;
        }
    }
    //Tim cung A[u][v], neu ton tai thi gan pi pi = L[u][v] va next[u][v]=v
    for (u = 1; u <= G->n; u++)
        for (v = 1; v <= G->n; v++)
            if (G->A[u][v] != 0)
            {
                pi1[u][v] = G->A[u][v];
                next[u][v] = v;
            }
    for (k = 1; k <= G->n; k++)
        for (u = 1; u <= G->n; u++)
            for (v = 1; v <= G->n; v++)
                if (pi1[u][k] + pi1[k][v] < pi1[u][v])
                {
                    pi1[u][v] = pi1[u][k] + pi1[k][v];
                    next[u][v] = next[u][k];
                }
}
// -----------------------------------------Rank--------------------------------------------
//Maxlenth nen cho toi da 100 thoi
//Bai toan chia keo thi cho rank +1 la ra so keo nho nhat cua 1 em
int rank[100];
//Khong ap dung cho vo huong
//nho khoi tao d[1->n]
void ranking(Graph_A_dinh_dinh *G)
{
    int d[Maxlength];
    //for nếu G->A[x][u] tồn tại thì du++
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            if (G->A[i][j] != 0)
                d[j]++;
    List S1, S2;
    S1.size = 0;
    int u;
    for (u = 1; u <= G->n; u++)
        if (d[u] == 0)
            S1.arr[S1.size++] = u;
    k = 0;
    while (S1.size > 0)
    {
        S2.size = 0;
        for (i = 0; i < S1.size; i++)
        {
            int u = S1.arr[i];
            rank[u] = k;
            int v;
            for (v = 1; v <= G->n; v++)
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (d[v] == 0)
                        S2.arr[S2.size++] = v;
                }
        }
        S1.size = 0;
        for (i = 0; i < S2.size; i++)
        {
            S1.arr[S1.size++] = S2.arr[i];
        }
        k++;
    }
}
// --------------------------To chuc thi cong--------------------------
void topo_sort(Graph_A_dinh_dinh *G, List *L)
{
    int deg[100];
    Queue Q;
    make_Null_Queue(&Q);
    L->size = 0;
    int i;
    for (i = 1; i <= G->n; i++)
    {
        deg[i] = degree(G, i);
        if (deg[i] == 0)
            en_Queue(&Q, i);
    }
    //Khi Queue khong rong
    while (Q.Front <= Q.Rear)
    {
        int u = de_Queue(&Q);
        L->arr[L->size++] = u;
        for (i = 1; i <= G->n; i++)
            if (G->A[u][i] != 0)
            {
                deg[i]--;
                if (deg[i] == 0)
                    en_Queue(&Q, i);
            }
    }
}
void t_T_toppo_Sort(Graph_A_dinh_dinh *G, )
    // ---------------giải thuật Kruskal----------------------
    int parent[100];
int findRoot(int u)
{
    if (parent[u] == u)
        return u;
    return findRoot(parent[u]);
}
int kruskal(Graph_Edge *G, Graph_Edge *T)
{
    int i, j, u, e;
    for (i = 0; i < G->m; i++)
    {
        for (j = 0; j < G->m - 1; j++)
            if (G->edges[j].index > G->edges[j + 1].index)
            {
                int temp_u = G->edges[j].a;
                int temp_v = G->edges[j].b;
                int temp_w = G->edges[j].index;
                G->edges[j].a = G->edges[j + 1].a;
                G->edges[j].b = G->edges[j + 1].b;
                G->edges[j].index = G->edges[j + 1].index;
                G->edges[j + 1].a = temp_u;
                G->edges[j + 1].b = temp_v;
                G->edges[j + 1].index = temp_w;
            }
    }
    init_Graph_Edge(T, G->n);
    for (u = 1; u <= G->n; u++)
        parent[u] = u;
    int sum_w = 0;
    for (e = 0; e < G->m; e++)
    {
        int u = G->edges[e].a;
        int v = G->edges[e].b;
        int w = G->edges[e].index;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u != root_v)
        {
            add_edge_Edge(T, u, v, w);
            parent[root_v] = root_u;
            sum_w += w;
        }
    }
    return sum_w;
}
// -------------------Giai thuat Prime--------------------
int Prim(Graph_A_dinh_dinh *G, Graph_A_dinh_dinh *T)
{
    T->n = G->n;
    int i, u, v;
    for (u = 1; u <= G->n; u++)
        pi[u] = 1000;
    pi[1] = 0;
    for (v = 1; v <= G->n; v++)
        if (G->A[1][v] != 0)
        {
            pi[v] = G->A[1][v];
            p[v] = 1;
        }
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    mark[1] = 1;
    int sum_w = 0;
    for (i = 1; i < G->n; i++)
    {
        int min_dist = 1000, min_u;
        for (u = 1; u <= G->n; u++)
            if (mark[u] == 0)
            {
                if (min_dist > pi[u])
                {
                    min_dist = pi[u];
                    min_u = u;
                }
            }
        u = min_u;
        mark[min_u] = 1;
        T->A[p[u]][u] = min_dist;
        sum_w += min_dist;
        for (v = 1; v <= G->n; v++)
            if (G->A[u][v] != 0 && mark[v] == 0)
                if (pi[v] > G->A[u][v])
                {
                    pi[v] = G->A[u][v];
                    p[v] = u;
                }
    }
    return sum_w;
}