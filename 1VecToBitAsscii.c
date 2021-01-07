#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef char Element_Type;
typedef struct Node{
	Element_Type Data;
	struct Node*Next;
}Node;
typedef Node*Position;
typedef Position Set;
void Make_Null_Set(Set *S){
	*S=(Node*)malloc(sizeof(Node));//*S luôn phai dat trong ngoac 
	(*S)->Next=NULL;
}
int Empty_Set(Set S){
	return S->Next==NULL;
}
int Member(Element_Type X, Set S){
	Position P=S;
	int found=0;
	while(P->Next!=NULL){
	if(P->Next->Data==X)found=1;
	P=P->Next;
	}
	return found;
}
void Insert_Set(Element_Type X,Set *S){
	if((Member(X,(*S))==1));
	else{
		Position P=*S;
		while(P->Next!=NULL&&P->Next->Data<X){
			P=P->Next;
		}
		Position temp=(Node*)malloc(sizeof(Node));
		temp->Data=X;
		temp->Next=P->Next;
		P->Next=temp;	
	}
}
void Delete_Set(Element_Type X,Set *S){
		if((Member(X,*S)!=1)) ;
	else{
		Position P=*S;
		while(P->Next!=NULL&&P->Next->Data<=X){
			P=P->Next;
		}
		Position temp=(Node*)malloc(sizeof(Node));
		temp=P->Next;
		P->Next=temp->Next;
		free(temp);
	}
}
void Intersection(Set A,Set B,Set *C){//giao cua hai tap hop
	Position P=A;
	Make_Null_Set(C);
	while(P->Next!=NULL){
		if(Member(P->Next->Data,B)==1) Insert_Set(P->Next->Data,C);
		P=P->Next;
	}
}
void Union(Set A,Set B,Set *C){
	Position P=A;
	Position Q=B;
	Make_Null_Set(C);
	while(P->Next!=NULL){
		Insert_Set(P->Next->Data,C);
		P=P->Next;
	}
	while(Q->Next!=NULL){
		Insert_Set(Q->Next->Data,C);
		Q=Q->Next;
	}
}
void Difference(Set A,Set B,Set *C){
	Make_Null_Set(C);
	Position P=A;
	while(P->Next!=NULL){
		if(Member(P->Next->Data,B)==0) Insert_Set(P->Next->Data,C);
		P=P->Next;
	}
}
void Read_Set(Set *S){
	int n,i=0;
	char X[100];
	printf("Nhap vao mot chuoi: ");
	gets(X);
	for(i;i<strlen(X);i++)
		Insert_Set(X[i],S);
}
void Print_Set(Set S){
	printf("\n");
	if(Empty_Set(S)==1) printf("	NULL");
	else{
	Position P=S;
	while(P->Next!=NULL){
		printf("	%d",P->Next->Data);
		P=P->Next;
	}
	}
	
}
