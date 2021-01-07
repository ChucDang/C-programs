#include <stdio.h>
#include <conio.h>
void Chuyen(int n, char A,char B,char C);
int main()
{
	char A='A',B='B',C='C';
	int n;
	printf("nhap vao so luong dia: ");scanf("%d",&n);
	Chuyen(n,A,B,C);
}
void Chuyen(int n, char A,char B,char C)
{
	if(n==1) { printf("chuyen dia thu %d tu cot %c sang cot %c \n",n,A,C);return;
	}
	Chuyen(n-1,A,C,B);
	Chuyen(1,A,B,C);
	Chuyen(n-1,B,A,C);
	return;
	
}
