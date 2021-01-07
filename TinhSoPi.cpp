#include<stdio.h>
int main()
{
	double c, res=0;
	int i=1,n=0;
	printf("nhap vao do chinh xac cua so pi:");
	scanf("%f",&c);
	while(1.0/(2*n+1)>=c)
	{
		res+=i*1.0/(2*n+1);
		i*=-1;
		n++;
	}
	res*=4;
	printf("gia tri so pi la: %f",res);
}
