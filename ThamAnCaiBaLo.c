#include <stdio.h>
#include <string.h>
typedef struct
{
    int soluong;
    char ten[25];
    float medium;
    int G, V;
} Dovat;
typedef struct
{
    int size;
    Dovat dovat[10];
} List;
//Duyet tu cuoi mang trung binh, lay trong luong chia cho
//day arr se luu so luong cua vat thu index;
//bien vitual se luu gia tri lon nhat co the, chua so so luong
//bien real luu so luong cua do vat.
void thamAn(List list[], int arr[], int TrongLuong)
{
    for (int i = 0; i <= list->size; i++)
    {
        int vitual = TrongLuong / (list->dovat[i].G);
        printf("%d\n", vitual);
        int real = list->dovat[i].soluong;
        if (vitual < real)
        {
            arr[i] = vitual;
        }
        else
        {
            arr[i] = real;
        }
        TrongLuong = TrongLuong - (list->dovat[i].G) * arr[i];
    }
}

//truoc la List ban dau, arr la List trung binh
//dung de sap xep lai theo trung binh gia tri
//bien arr se luu day index vat, va gia tri trung binh cua vat
void sapxep(List list[])
{
    for (int i = 1; i <= list->size; i++)
    {
        int j = i;
        while ((j > 0) && (list->dovat[j].medium > list->dovat[j - 1].medium))
        {
            Dovat temp;
            temp = list->dovat[j];
            list->dovat[j] = list->dovat[j - 1];
            list->dovat[j - 1] = temp;
            j--;
        }
    }
}
int main()
{
    printf("Nhap vao trong luong cua BA Lo:\n");
    int W;
    float TongTL = 0.0, TongGT = 0.0;
    scanf("%d", &W);
    FILE *f = freopen("dovat.inp", "r", stdin);
    List L;
    L.size = -1;
    while (!feof(f))
    {
        L.size++;
        fflush(stdin);
        scanf("%d%d%d%[^\n]", &L.dovat[L.size].G, &L.dovat[L.size].V, &L.dovat[L.size].soluong, &L.dovat[L.size].ten);
        L.dovat[L.size].medium = 1.0 * (L.dovat[L.size].V) / (L.dovat[L.size].G);
    }
    int arr[L.size];
    fclose(f);
    sapxep(&L);
    thamAn(&L, arr, W);
    printf("Phuong an cai ba lo 2 dung giai thuat tham an:\n");
    printf("|---|------------------|---------|---------|---------|----------|\n");
    printf("|STT|    Ten Do Vat    | TLuong  | Gia Tri | Don Gia | Phuong An|\n");
    printf("|---|------------------|---------|---------|---------|----------|\n");

    for (int i = 0; i <= L.size; i++)
    {
        printf("|%2d |%-18s|%9d|%9d|%9.2f|%6d    |\n", i + 1, L.dovat[i].ten, L.dovat[i].G, L.dovat[i].V, L.dovat[i].medium, arr[i]);
        TongTL = TongTL + arr[i] * L.dovat[i].G;
        TongGT = TongGT + arr[i] * L.dovat[i].V;
    }
    printf("|---|------------------|---------|---------|---------|----------|\n");
    printf("Trong luong cua BA lO = %d\n", W);
    printf("Tong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}