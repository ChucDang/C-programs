#include<stdio.h>
#include<stdlib.h>
typedef int Element_Type;
typedef struct Node{
	Element_Type Element;
	struct Node* Next;
}Node;
typedef Node* Position;
typedef Position List;
void Make_Null_List(List *L){
	(*L)=(Node*)malloc(sizeof(Node));
	(*L)->Next=NULL;
}
int Emty_List(List L){
	return L->Next==NULL;
}
Position First(List L){
	return L;
}
Position End(List L){
	Position P=First(L);
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}
Position Next(Position P, List L){
	return P->Next;
}
Position Previous(Position P, List L){
	Position Q=First(L);
	while(Q->Next==P)
	return P;
}
Element_Type Retrieve(Position P, List L){
	return P->Next->Element;
}
Position Locate(Element_Type X,List L){
	Position P=First(L),E=End(L);
	int Found=0;
	while(P<=E&&!Found)
		if(P->Next->Element==X) Found=1;
		else P=P->Next; 	
	return P;					
}
void Insert_List(Element_Type X, Position P, List *L){
	Position T;
	T=(Node*)malloc(sizeof(Node));
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}
void Delete_List(Position P,  List *L){
	Position Temp;
	Temp=P->Next;
	P->Next=Temp->Next;
	free(Temp);
}
void Read_List(List *L){
	int i,number;
	Element_Type X;
	printf("Nhap vao so luong phan tu cua danh sach L: ");
	scanf("%d",&number);
	printf("Nhap vao danh sach L: ");
	for(i=1;i<=number;i++){
		scanf("%d",&X);
		Insert_List(X,End(*L), L);
	}
}
void Print_List(List L){
	Position P=First(L);
	while(P->Next!=NULL ){
		printf("%d ",Retrieve(P,L));
		P=P->Next;
	}	
}


