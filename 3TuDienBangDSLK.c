#include <stdio.h>
#include <string.h>
#include<malloc.h>
typedef struct{
	char Eng[100];
	char Viet[100];
}Data;
typedef Data Element_Type;
typedef struct Node{
	Element_Type Element;
	struct Node*Next;
}Node;
typedef Node*Position;
typedef Position Dictionary;
void Make_Null_Dic(Dictionary *D){
	(*D)=(Node*)malloc(sizeof(Node));
	(*D)->Next=NULL;
}
Position End_Dic(Dictionary D){
	Position P=D;
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}
int Empty_Dic(Dictionary D){
	return D->Next==NULL;
}
void Insert_Dic(Element_Type X,Dictionary *D){
	Position temp=(Node*)malloc(sizeof(Node));
	Position P=End_Dic(*D);
	temp->Element=X;
	temp->Next=P->Next;
	P->Next=temp;
}
void Delete_Dic(Element_Type X,Dictionary *D){
	Position P=*D;
	while(P!=End_Dic(*D)){
		if(strcmp(P->Next->Element.Eng,X.Eng)==0){
			Position Q=(Node*)malloc(sizeof(Node));
				Q=P->Next;
				P->Next=Q->Next;
				free(Q);
				break;
		}
		P=P->Next;
	}
}
void Read_Dic(Dictionary *D){
	printf("Nhap vao so luong phan tu muon them: \n");
	int n,i=1;
	Element_Type X;
	scanf("%d",&n);
	while(n>0){
		printf("Tu vung thu %d: \n",i);
		printf("	English: ");
		gets(X.Eng);
		printf("	Vietnamese: ");
		gets(X.Viet);
		Insert_Dic(X,D);
		n--;
		i++;
	}
}
void Print_Dic(Dictionary D){
	Position P=D;
	int i=1;
	while(P!=End_Dic(D)){
		printf("Tu vung thu %d: \n",i);
		printf("	English: %s 	Vietnamese: %s \n",P->Next->Element.Eng,P->Next->Element.Viet);
		P=P->Next;
		i++;
	}
}
