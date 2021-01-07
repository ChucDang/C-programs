#include<stdio.h>
#include<malloc.h>
typedef struct {
	char Eng[100];
	char Viet[100];
}Data;
typedef Data Element_Type;
typedef struct Node{
	Element_Type Element;
	struct Node*Prev;
	struct Node*Next;
}Node;
typedef Node* Position;
typedef struct{
	Position Head;
	Position Tail;
}Double_List;
void Make_Null_Double_List(Double_List *DL){
	(*DL).Head=NULL;
}
int Empty_Double_List(Double_List DL){
	return DL.Head==NULL;
}
Position Head(Double_List DL){
	return DL.Head;
}
Position End(Double_List DL){
	return DL.Tail;
}
/*	Ham nay khong xai trong tu dien
Element_Type Retrieve_Double_List(Position P, Double_List DL){
	return P->Element;
}*/
void Insert_Head_Double_List(Element_Type X,Double_List *DL){
	if(Empty_Double_List(*DL)){
		Position T;
		T=(Node*)malloc(sizeof(Node));
		T->Element=X;
		(*DL).Head=T;
		(*DL).Tail=T;
	}else{
		Position P;
		P=(Node*)malloc(sizeof(Node));
		P->Element=X;
		P->Next=(*DL).Head;
		(*DL).Head->Prev=P;
		(*DL).Head=P;
	}
}
void Insert_Tail_Double_List(Element_Type X,Double_List *DL){
	if(Empty_Double_List(*DL)){
		Position T;
		T=(Node*)malloc(sizeof(Node));
		T->Element=X;
		(*DL).Head=T;
		(*DL).Tail=T;
	}else{
		Position P;
		P=(Node*)malloc(sizeof(Node));
		P->Element=X;
		P->Prev=(*DL).Tail;
		(*DL).Tail->Next=P;
		(*DL).Tail=P;
	}
}
void Delete_Double_List(Position P, Double_List *DL){
	if(Empty_Double_List(*DL))
		printf("Danh sach rong!");
	if(P==(*DL).Head)
		(*DL).Head=P->Next;
	if(P==(*DL).Tail)
		(*DL).Tail=P->Next;
	else{
		P->Next->Prev=P->Prev;
	 	P->Prev->Next=P->Next;
	}
}
void Read_Double_List(Double_List *DL){
	printf("Nhap vao luong luong phan tu: ");
	int n,i;
	scanf("%d",&n);
	Element_Type X;
	for(i=1;i<=n;i++){
		printf("Phan tu thu %d :",i);
		fflush(stdin);
		printf(" Nhap tu vung: ");
		gets(X.Eng);
		fflush(stdin);
		printf(" Nhap nghia: ");
		gets(X.Viet);
		Insert_Tail_Double_List(X,DL);
		}
	}
void Print_Double_List(Double_List DL){
	printf("Danh sach vua nhap la: ");
	Position H=DL.Head,T=DL.Tail;
	while(H!=T->Next){
		printf("\tEnglish: %s\tVietnamese: %s\n",H->Element.Eng,H->Element.Viet);
		H=H->Next;
	}
}

