#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define B 4
#include<string.h>
typedef struct{
	char Eng[10];
	char Viet[100];
	int k;
}Data1;
typedef Data1 Element_Type;
typedef struct Node{
	Element_Type Data;
	struct Node*Next;
}Node;
typedef Node*Position;
typedef Position Dictionary[B];
void Make_Null_Dic(Dictionary *D){
	int i;
	for(i=0;i<B;i++){
		(*D)[i]=(Node*)malloc(sizeof(Node));//khai bao 
		(*D)[i]->Next=NULL;
	}
}
int H( int m){
	return m%B;
}
int Member(Element_Type X,Dictionary D){
	Position P=D[H(X.k)];
	int found=0;
	while(P->Next!=NULL&&!found){//nho la P->Next!=NULL 
		if(strcmp(P->Next->Data.Eng,X.Eng)==0)found=1;
		else P=P->Next;
	}
	return found; 
}
void Insert(Element_Type X,Dictionary *D){
	int Bucket;
	if(Member(X,*D)) printf(" Phan tu da co trong danh sach");
	else{    
		Bucket=H(X.k);
		Position Temp;
		Temp=(Node*)malloc(sizeof(Node));
		Temp->Data=X;
		Temp->Next=(*D)[Bucket]->Next;
		(*D)[Bucket]->Next=Temp;                                      
	}
}
void Delete(char str[],Dictionary *D){//can than thuat toan delete nay,
	int Bucket=1,i;
	Position P,temp;
	for(i=0;i<B;i++){
		P=(*D)[H(i)];
		while(P->Next!=NULL) 
		if(strcmp(P->Next->Data.Eng,str)==0){
			temp=P->Next;
			P->Next=temp->Next;
			free(temp);
		}
		else P=P->Next;                                                                                                                                                                                                                                                                                                                                                                                                                                             
	}
}
void Read(Dictionary *D){
	printf("Nhap vao so luong phan tu trong danh sach: ");
	int n;
	scanf("%d",&n);
	int i,j;
	Element_Type X;
	for(i=1;i<=n;i++){
		printf("Tu vung thu %d: ",i);
		fflush(stdin);
		gets(X.Eng);
		printf("Nghia tieng Viet: ");
		fflush(stdin);
		gets(X.Viet);
		X.k=rand();
		Insert(X,D);
	}
}
void Print(Dictionary D){
	int i;
	for(i=0;i<B;i++){
		Position P=D[H(i)];
		while(P->Next!=NULL){
		printf("\tEnglish: %s\t Vietnamese: %s\t key: %d\n",P->Next->Data.Eng,P->Next->Data.Viet,P->Next->Data.k);
		P=P->Next;
		}
	}
}
