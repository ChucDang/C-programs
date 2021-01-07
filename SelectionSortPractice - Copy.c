#include <stdio.h>
#include <malloc.h>
typedef struct
{
    char ten[25];
    int key;
} KeyType;
void swap(KeyType *a, KeyType *b)
{
    KeyType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
KeyType *Read(int *n)
{
    FILE *f = fopen("data.txt", "r");
    int i = 0;
    KeyType *dsdv = (KeyType *)malloc(sizeof(KeyType));
    while (!feof(f))
    {
        fscanf("%d%[^\n]", dsdv[i].key, dsdv[i].ten);
        i++;
        dsdv = (KeyType *)malloc(sizeof(KeyType) * (i + 1));
    }
    *n = i - 1;
    return dsdv;
}
void SelectionSort(KeyType *dsdv, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int min_index = i;
        int min_key = dsdv[i].key;
        for (j = i + 1; j <= n; j++)
        {
            if (dsdv[j].key < min_key)
            {
                min_key = dsdv[j].key;
                min_index = j;
            }
        }
        swap(&dsdv[i], &dsdv[min_index]);
    }
}
int main()
{
    KeyType *dsdv;
    int n = 0;
    int i;
    dsdv = Read(&n);
    printf("Day so ban dau la:\n");
    printf("|--------------|--------------|\n");
    for (i = 0; i <= n; i++)
    {
        printf("|%-15s|%-6d|\n", dsdv[i].ten, dsdv[i].key);
    }
    printf("|--------------|--------------|\n");
}