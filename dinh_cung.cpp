#include <stdio.h>
#define Max_M 500
typedef struct
{
    int x, y;
} Edge;
typedef struct
{
    Edge edge[Max_M];
    int n, m;
} Graph;
void ini_Graph(Graph *G, int n)
{

    G->n = n;
    G->m = 0;
}
void add_Edge(Graph *G, int x, int y)
{
    G->edge[G->m].x = x;
    G->edge[G->m].y = y;
    G->m += 1;
}
int degree(Graph *G, int x)
{
    int count = 0;
    for (int i = 0; i < G->m; i++)
    {
        if (G->edge[i].x == x ||
            G->edge[i].y == x)
            count++;
    }
    return count;
}
int adjacent(Graph *G, int x, int y)
{
    for (int i = 0; i < G->m; i++)
    {
        if ((G->edge[i].x == x && G->edge[i].y == y) || (G->edge[i].y == x && G->edge[i].x == y))
        {
            return 1;
        }
    }
    return 0;
}
void neighbours(Graph *G, int x)
{
    for (int i = 0; i < G->m; i++)
    {
        if (G->edge[i].x == x)
        {
            printf(" %d\t", G->edge[i].y);
        }
        else
        {
            if (G->edge[i].y == x)
            {
                printf(" %d\t", G->edge[i].x);
            }
        }
    }
}
int main()
{
    Graph G;
    int n;
    int i = 0;
    int x, y;
    FILE *f = fopen("a.txt", "r");
    fscanf(f, "%d", &n);
    ini_Graph(&G, n);
    while (!feof(f))
    {
        fscanf(f, "%d", &x);
        fscanf(f, "%d", &y);
        add_Edge(&G, x, y);
        i++;
    }
    int k = 1;
    printf("Degree of 1 is %d \n", degree(&G, k));
    x = 2;
    y = 1;
    printf("%d co ke voi %d hay khong? %d\n", x, y, adjacent(&G, x, y));
    printf("Các đỉnh kề của %d là: \n", x);
    neighbours(&G, x);
}
