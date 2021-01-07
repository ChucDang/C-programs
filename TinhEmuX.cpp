#include<stdio.h>
#include<math.h>
int main()
{
	double c,x,res=1,tr=1;/*tr la bien trung gian*/
	long n=1;
	printf("nhap vao do chinh xac va gia tri x :");
	scanf("%Lf %Lf",&c,&x);/*phai la Lf vi neu chi la f thi bi thieu bo nho nen chi ra 1.00000000*/
	while(1)
	{
		if(x==0) 
		{
			printf("x khong hop le !!");break;
		}
		else
		{
		res+=tr*x/n;
		tr*=x/n;
		n++;
		if(((-c<=tr)&&(tr<=c))) break;
		}
	}
	printf("gia tri cua so e mu x la: %Lf",res);
}

