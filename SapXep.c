#include <stdio.h>
#define keytype int
#define othertype float
typedef struct
{
    keytype key;
    othertype other;
} recordtype;

void SelectionSort(recordtype a[], int n)
{
    int lowindex;
    keytype lowkey;
    int i,j;
    for (i = 0; i <= n - 2; i++)
    {
        lowkey = a[i].key;
        lowindex = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[j].key < lowkey)
            {
                lowindex = j;
                lowkey = a[j].key;
            }
        }
        recordtype temp;
        temp = a[i];
        a[i] = a[lowindex];
        a[lowindex] = temp;
    }
}
void InsertionSort(recordtype a[], int n)
{
	int i;
    for (i = 0; i <= n - 1; i++)
    {
        int j = i;
        while ((j > 0) && (a[j].key < a[j - 1].key))
        {
            recordtype temp;
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

void BubbleSort(recordtype a[], int n)
{
	int i,j;
    for (i = 0; i <= n - 2; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            if (a[j].key < a[i].key)
            {
                recordtype temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

keytype findPivot(recordtype a[], int i, int j)
{
    int k = i + 1;
    keytype firstkey = a[i].key;
    while ((k <= j) && (a[k].key == a[i].key))k++;
    if (k > j) return -1;
    if (a[k].key > firstkey) return k; return i;
}
keytype partition(recordtype a[], int i, int j, int pivot)
{
    int L = i, R = j;
    while (L <= R)
    {
        while (a[L].key < pivot) L++;
        while (a[R].key >= pivot) R--;
        if (L < R)
        {
            swap(&a[L],&a[R]);
        }
    }
    return L;
}
void QuickSort(recordtype a[], int i, int j)
{
    keytype pivot;
    int pivotindex = findPivot(a, i, j);
    int k;
    if (pivotindex != -1)
    {
        pivot = a[pivotindex].key;
        k = partition(a, i, j, pivot);
        QuickSort(a, i, k - 1);
        QuickSort(a, k, j);
    }
}
// -------------------------------QuickSort bien the----------------------------
keytype findPivot1(recordtype a[], int i, int j)
{
    int k = i + 1;
    keytype firstkey = a[i].key;
    while ((k <= j) && (a[k].key == a[i].key)) k++;
    if (k > j) return -1;
    if (a[k].key > firstkey) return i; return k;
}
keytype partition1(recordtype a[], int i, int j, int pivot)
{
    int L = i, R = j;
    while (L <= R)
    {
        while (a[L].key <= pivot) L++;
        while (a[R].key > pivot) R--;
        if (L < R)
        {
            swap(&a[L],&a[R]);
        }
    }
    return L;
}
void QuickSort1(recordtype a[], int i, int j)
{
    keytype pivot;
    int pivotindex = findPivot1(a, i, j);
    int k;
    if (pivotindex != -1)
    {
        pivot = a[pivotindex].key;
        k = partition1(a, i, j, pivot);
        QuickSort1(a, i, k - 1);
        QuickSort1(a, k, j);
    }
}
void swap(recordtype *a, recordtype *b){
	recordtype temp;
	temp =*a;
	*a=*b;
	*b=temp;
}
// ---------------------------Sap xep HeapSort--------------------
void PushDown(recordtype a[], int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
    {
        if (last == 2 * r + 1)
        {
            if (a[r].key > a[last].key)
            {
                swap(&a[r],&a[last]);
            }
            r = last;
        }
        else if ((a[r].key > a[2 * r + 1].key) && (a[2 * r + 1].key <= a[2 * r + 2].key))
        {
            swap(&a[r],&a[2*r+1]);
            r = 2 * r + 1;
        }
        else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key))
        {
            swap(&a[r],&a[2*r+2]);
            r = 2 * r + 2;
        }
        else
        {
            r = last;
        }
    }
}
void HeapSort(recordtype a[], int n)
{
	int i;
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        PushDown(a, i, n);
    }
    for (i = n; i >= 1; i--)
    {
        swap(&a[0],&a[i]);
        PushDown(a, 0, i - 1);
    }
    swap(&a[0],&a[1]);
}
int main()
{
    int n;
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    recordtype a[n];
    int i;
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Day so truoc khi sap xep la: \n");
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    // printf("Sap xep chon: \n");
    // SelectionSort(a, n);
    // printf("Sap xep xen: \n");
    // InsertionSort(a, n);
    // printf("Sap xep noi bot: \n");
    // BubbleSort(a, n);
    // printf("Sap xep QuickSort: \n");
    QuickSort1(a, 0, n);
    // printf("Sap xep QuickSort bien the: \n");
    // QuickSort1(a, 0, n - 1);
    printf("Sap xep Vung dong HeapSort:\n");
    //HeapSort(a, n);
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
