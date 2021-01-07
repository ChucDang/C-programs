#include <stdio.h>
#include <malloc.h>
typedef struct
{
	char ten;
	int key;
} DoVat;
DoVat *Read(int *n, int *W)
{
	int i = 0;
	FILE *f = fopen("data.txt", "r");
	fscanf(f, "%d", W);
	DoVat *dsdv = (DoVat *)malloc(sizeof(DoVat));
	while (!feof(f))
	{
		fscanf(f, "%d", &dsdv[i].key);
		i++;
		dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1));
	}
	*n = i - 2;
	fclose(f);
	return dsdv;
}
void swap(DoVat *a, DoVat *b)
{
	DoVat temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void pushDown(DoVat *dsdv, int first, int last)
{
	int r = first;
	while (last >= 2 * r + 1)
	{
		if ((last == 2 * r + 1) && (dsdv[r].key > dsdv[last].key))
		{

			swap(&dsdv[r], &dsdv[last]);
			r = last;
		}
		else if ((dsdv[r].key > dsdv[2 * r + 1].key) && (dsdv[2 * r + 1].key <= dsdv[2 * r + 2].key))
		{
			swap(&dsdv[r], &dsdv[2 * r + 1]);
			r = 2 * r + 1;
		}
		else if ((dsdv[r].key > dsdv[2 * r + 2].key) && (dsdv[2 * r + 2].key < dsdv[2 * r + 1].key))
		{
			swap(&dsdv[r], &dsdv[2 * r + 2]);
			r = 2 * r + 2;
		}
		else
		{
			r = last;
		}
	}
}
void heapSort(DoVat *dsdv, int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
	{
		pushDown(dsdv, i, n);
	}
	for (i = n; i >= 1; i--)
	{
		swap(&dsdv[0], &dsdv[i]);
		pushDown(dsdv, 0, i - 1);
	}
	swap(&dsdv[0], &dsdv[1]);
}
int main()
{
	DoVat *dsdv;
	int n, W;
	dsdv = Read(&n, &W);
	printf("danh sach truoc khi sap xep\n");
	int i;
	for (i = 0; i <= n; i++)
	{
		printf("%d ", dsdv[i].key);
	}
	printf("Danh sach sau khi sap xep\n");
	heapSort(dsdv, n);
	for (i = 0; i <= n; i++)
	{
		printf("%d ", dsdv[i].key);
	}
	return 0;
}
