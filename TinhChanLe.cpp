#include<stdio.h>
#include<assert.h>
void chan(int n);
void le(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return chan(n);
}
void chan(int n)
{
	if(n==0) return 1;
	if(n==1) return 0;
	return le(n);
}
int main()
{
	printf("nhap vao so n: ");
	scanf("%d",&n);
	chan(n);
	if(n);
}
