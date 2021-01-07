#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct{
	int ma;
	char ten[25];
	float khoiluong;
}KhachHang;
typedef KhachHang KhachHang;
typedef struct Node{
	KhachHang Data;
	struct Node*Left;
	struct Node*Right;
}Node;
typedef Node* BST;
void Make_Null(BST *T){
	(*T)=NULL;
}
void Print(KhachHang X){
	printf("Ma khach hang %d, ten khach hang: %s, khoi luong nuoc su dung: %f",X.ma,X.ten,X.khoiluong);
}
BST Search(int ID,BST T){
	if(T!=NULL){// cho nay phai o trong ngoac
		if(T->Data.ma==ID) return T;
		else if(T->Data.ma>ID) return Search(ID,T->Left);
		else if(T->Data.ma<ID) return Search(ID,T->Right);
	}
	else return NULL;
}
void Insert_Node(KhachHang X,BST *T){
	if((*T)==NULL){
		(*T)=(Node*)malloc(sizeof(Node));
		(*T)->Data=X;
		(*T)->Left=NULL;
		(*T)->Right=NULL;
	}
	if((*T)->Data.ma==X.ma);
	else if((*T)->Data.ma>X.ma) Insert_Node(X,&(*T)->Left);//truoc if phai co else de tranh hieu lam
	else Insert_Node(X,&(*T)->Right);
}
void Read(int n,BST *T){
	int i;
	KhachHang X;
	for(i=1;i<=n;i++){
		printf("\nThong tin khach hang thu %d: \nMa so: ",i);
		scanf("%d",&X.ma);
		while(Search(X.ma,*T)!=NULL){
			printf("\nMa so da ton tai, vui long nhap lai: \n");
			scanf("%d",&X.ma);
		}
		printf("\nTen khach hang: \n"); fflush(stdin); gets(X.ten);
		printf("\nKhoi luong nuoc su dung:\n"); scanf("%f",&X.khoiluong);
		Insert_Node(X,T);//cai nay phai o trong
	}
}

