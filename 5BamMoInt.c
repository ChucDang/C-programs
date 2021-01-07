#include<stdio.h>
#include<malloc.h>
#define B 100
typedef int Element_Type;
typedef struct Node{
	Element_Type Data;
	struct Node*Next;
}Node;
typedef Node*Position;
typedef Position Dictionary[B];
void Make_Null_Dic(Dictionary *D){
	int i;
	for(i=0;i<B;i++){
		(*D)[i]=(Node*)malloc(sizeof(Node));
		(*D)[i]->Next=NULL;
	}
}
int H(Element_Type X){
	return X%B;
}
int Member(Element_Type X,Dictionary D){
	Position P=D[H(X)];
	int found=0;
	while(P->Next!=NULL&&!found){
		if(P->Next->Data==X)found=1;
		else P=P->Next;
	}
	return found; 
}
void Insert(Element_Type X,Dictionary *D){
	Position P=(*D)[H(X)];
	if(Member(X,*D)) printf(" Phan tu da co trong danh sach");
	else{
		while(P->Next!=NULL){
			P=P->Next;
		}
	}
	Position temp=(Node*)malloc(sizeof(Node));
	 		 temp->Data=X;
	 	     temp->Next=P->Next;
	 	     P->Next=temp;
}
void Insert_Order(Element_Type X,Dictionary *D){
	Position P=(*D)[H(X)];
	if(Member(X,*D)) printf(" Phan tu da co trong danh sach");
	else{
		while(P->Next!=NULL&&P->Next->Data<X){
			P=P->Next;
		}
	}
	Position temp=(Node*)malloc(sizeof(Node));
	 		 temp->Data=X;
	 	     temp->Next=P->Next;
	 	     P->Next=temp;
}
void Delete(Element_Type X,Dictionary *D){
	Position P=(*D)[H(X)];
	if(!Member(X,*D))printf("X khong ton tai trong tu dien.");
	else{
		while(P->Next!=NULL&&P->Next->Data!=X){
			P=P->Next;
		}
		Position temp=(Node*)malloc(sizeof(Node));
			temp=P->Next;
			P->Next=temp->Next;
			free(temp);
	}
}
void Read(Dictionary *D){
	printf("Nhap vao so luong phan tu trong danh sach: ");
	int n;
	scanf("%d",&n);
	int i,j;
	Element_Type X;
	for(i=1;i<=n;i++){
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		Insert_Order(X,D);
	}
}
void Print(Dictionary D){
	int i;
	for(i=0;i<B;i++){
		Position P=D[H(i)];
		while(P->Next!=NULL){
		printf("\tPhan tu: %d\n",P->Next->Data);
		P=P->Next;
		}
	}
}
