#include <stdio.h>
#include <malloc.h>
void swap(int *a, int *b)
{
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}
typedef struct
{
    float G, V, DG;
    int PA, SL;
    char ten[25];
} DoVat;
DoVat *ReadFromFile(float *W, int *n)
{
    FILE *f;
    f = fopen("dovat.inp", "r");
    fscanf(f, "%f", W);
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%f%f%d%[^\n]", &dsdv[i].G, &dsdv[i].V, &dsdv[i].SL, &dsdv[i].ten);
        dsdv[i].DG = dsdv[i].V / dsdv[i].G;
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1));
        printf("%d", dsdv[0].G);
        break;
    }
    *n = i;
    fclose(f);
    return dsdv;
}
void Insersort(DoVat *dsdv, int n)
{
    for (int i = 0; i <= n; i++)
    {
        int j = i;
        while ((j > 0) && (dsdv[i].DG > dsdv[i - 1].DG))
        {
            DoVat temp;
            temp = dsdv[i];
            dsdv[i] = dsdv[i - 1];
            dsdv[i - 1] = temp;
            j--;
        }
    }
}
int main()
{
    float TGT, TTL, W, GTLNTT, CT;
    FILE *f = fopen("dovat.inp", "r");
    fscanf(f, "%f", &W);
    DoVat *dsdv = (DoVat *)malloc(sizeof(DoVat));
    int n = 0;
    //Insersort(dsdv, n);
    ReadFromFile(&W, &n);
    // printf("Phuong an cai ba lo 2 dung giai thuat nhanh can:\n");
    // printf("|---|------------------|---------|---------|---------|----------|\n");
    // printf("|STT|    Ten Do Vat    | TLuong  | Gia Tri | Don Gia | Phuong An|\n");
    // printf("|---|------------------|---------|---------|---------|----------|\n");

    // for (int i = 0; i <= n; i++)
    // {
    //     printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d    |\n", i + 1, dsdv[i].ten, dsdv[i].G, dsdv[i].V, dsdv[i].DG, dsdv[i].PA);
    //     TTL = TTL + dsdv[i].PA * dsdv[i].G;
    //     TGT = TGT + dsdv[i].PA * dsdv[i].V;
    // }
    // printf("|---|------------------|---------|---------|---------|----------|\n");
    // printf("Trong luong cua BA lO = %f\n", W);
    // printf("Tong trong luong = %-9.2f\n", TTL);
    // printf("Tong gia tri = %-9.2f\n", TGT);
    // free(dsdv);
}