#include"StackListLib.c"
#include<string.h>
int main(){
	char C[100];
	int count=0,i,temp,k;
	Stack S;
	Make_Null_Stack(&S);
	printf("Nhap vao mot bieu thuc toan hoc: ");
	gets(C);
	for(i=strlen(C)-1;i>=0;i--){
		if(C[i]==40){//dau ngoac truoc
			while(C[i]!=41){
				if(C[i]>=48&&C[i]<=57) Push(C[i],&S);
				else{
					if(C[i]==42){
						 temp=C[i-1]*C[i+1];
						 Pop(&S);
						 Pop(&S);
						 Push(temp,&S);
					}
					if(C[i]==43){
						 temp=C[i-1]+C[i+1];
						 Pop(&S);
						 Pop(&S);
						 Push(temp,&S);
					}
					if(C[i]==45){
						 temp=C[i-1]-C[i+1];
						 Pop(&S);
						 Pop(&S);
						 Push(temp,&S);
					}
					if(C[i]==47){
						 temp=C[i-1]/C[i+1];
						 Pop(&S);
						 Pop(&S);
						 Push(temp,&S);
					}
					if(C[i]==37){
						 temp=C[i-1]%C[i+1];
						 Pop(&S);
						 Pop(&S);
						 Push(temp,&S);
					}
				}
			}
		}
		else
	}
	
		
	}
