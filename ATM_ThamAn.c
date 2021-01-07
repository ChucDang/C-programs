#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct
{
    char arr[40];
} Chuoi;

void thamAn(int tra[], int arr[], int SoTien, int index)
{
    while (SoTien > 9999)
    {
        int temp = 0;
        temp = SoTien / arr[index];
        if (temp > 0)
        {
            tra[index] = temp;
            SoTien -= arr[index] * temp;
        }
        else
        {
            tra[index] = 0;
        }
        index--;
    }
}
int main()
{
    printf("Nhap vao so tien muon rut: \n");
    int n;
    fflush(stdin);
    scanf("%d", &n);
    int index = -1;
    Chuoi chuoi[40];
    FILE *f = freopen("d.inp", "r", stdin);
    int arr[100];
    while (!feof(f))
    {
        index++;
        scanf("%d", &arr[index]);
        gets(chuoi[index].arr);
    }
    fclose(f);
    // for (int i = 0; i < index; i++)
    // {
    //     printf("%d", arr[i]);
    //     for (int j = 0; j < strlen(chuoi[i].arr); j++)
    //     {
    //         printf("%c", chuoi[i].arr[j]);
    //     }
    //     printf("\n");
    // }
    int tra[index];
    for (int i = 0; i < index; i++)
    {
        tra[i] = 0;
    }

    thamAn(tra, arr, n, index);
    for (int i = 0; i <= index; i++)
    {
        printf("%d %d\n", tra[i], arr[i]);
    }
}