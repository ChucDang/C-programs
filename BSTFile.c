#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct{
	int ma_sv;
	char ten[25];
	float diem_tb;
}SinhVien;
typedef struct Node{
	SinhVien Data;
	struct Node*Left;
	struct Node*Right;
}Node;
typedef Node * BST;
void Make_Null_BST(BST *T){
	(*T)=NULL;
}
int Empty_BST(BST T){
	return T==NULL;
}
BST Left_Child(BST T){
	if(!Empty_BST(T)) return T->Left;
	else return NULL;
}
BST Right_Child(BST T){
	if(!Empty_BST(T))return T->Right;
	else return NULL;
}
void Insert_BST(SinhVien X, BST *T){
	if(Empty_BST(*T)){//Neu cho nay de (*T) thi khong chay,can than cho nay:
		(*T)=(Node*)malloc(sizeof(Node));
		(*T)->Data=X;
		(*T)->Left=NULL;
		(*T)->Right=NULL;	
	}
	else if(X.ma_sv<(*T)->Data.ma_sv) Insert_BST(X,&(*T)->Left);
		else if(X.ma_sv>(*T)->Data.ma_sv) Insert_BST(X,&(*T)->Right);
	}
void Read_From_File( BST *T){
	SinhVien X;
	int L;
	FILE *f;
	f = fopen("SinhVien.txt","r");
	if(f){
		while(!feof(f)){
			fscanf(f,"%d",&X.ma_sv);
			fscanf(f,"%f",&X.diem_tb);
			fgets(X.ten,25,f);
			L=strlen(X.ten);
			if(X.ten[L-1]=='\n')
			X.ten[L-1]='\0';
			Insert_BST(X,T);
		}
		fclose(f);
	}
	else printf("Mo file loi!");
}
void Print(SinhVien X){
	printf("%5d\t%-25s\t%5.2f\n",X.ma_sv,X.ten,X.diem_tb);
}
void In_Order(BST T){
	if(!Empty_BST(T)){
		In_Order(Left_Child(T));
		Print(T->Data);
		In_Order(Right_Child(T));
	}
}
int main(){
	BST T;
	Make_Null_BST(&T);
	Read_From_File(&T);
	In_Order(T);
	return 0;
}
