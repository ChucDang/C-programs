#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define B 6
typedef struct{
	char English[20];
	char Vietnamese[50];
}Word_Pair;
typedef Word_Pair Element_Type;
typedef struct Node{
	Element_Type Data;
	struct Node*Next;
}Node;
typedef Node*Position;
typedef Node*Dictionary[B];
void Make_Null_Dictionary(Dictionary *D){
	int i=0;
	for(i;i<B;i++){
		(*D)[i]=(Node*)malloc(sizeof(Node));
		(*D)[i]->Next=NULL;
	}
}
int H(char st[]){
	return strlen(st)%B;
}
void Insert(Element_Type X, Dictionary *D){
	int i=H(X.English);
	Position Q=(*D)[i];
	int found=0;
	while(Q->Next!=NULL && !found){
		if(strcmp(Q->Next->Data.English,X.English)==0) found=1;
		else Q=Q->Next;
	}
	if(found==1) printf("\nTu vung da ton tai.\n");
	else{
		Position temp=(Node*)malloc(sizeof(Node));
		temp->Data=X;
		temp->Next=Q->Next;
		Q->Next=temp;
	}
}
int Member(char X[],Dictionary D){
	int i=0,found=0;
	Position P=D[H(X)];
		while(P->Next!=NULL&& i<B&&!found){
		if(strcmp(P->Next->Data.English,X)==0) found=1;
		else{
			P=P->Next;
			i++;
		}
		}
    	return found;	
}
void Delete(char X[],Dictionary *D){
	int i=0,found=0;
	Position P=(*D)[H(X)];
		while(P->Next!=NULL&& i<B&&!found){
		if(strcmp(P->Next->Data.English,X)==0) found=1;
		else{
			P=P->Next;
			i++;
		}
		if(found==0) printf("Khong ton tai tu vung vua nhap.");
		else{
			Position temp=(Node*)malloc(sizeof(Node));
			temp=P->Next;
			P->Next=temp->Next;
			free(temp);
		}
}
}
void Read(Dictionary *D){
	printf("\nNhap vao so luong tu vung: ");
	int i,n;scanf("%d",&n);
	Element_Type X;
	for(i=1;i<=n;i++){
		printf("\nNhap vao tu vung thu %d: \n\t English: ",i);
		fflush(stdin);
		gets(X.English);
		printf("\t Vietnamese: ");gets(X.Vietnamese);
		Insert(X,D);
	}
}
void Print(Dictionary D){
	printf("\t\t Danh sach tu vung:\n");
	int i;
	for (i=0;i<B;i++){
		Position Q=D[i];
		while(Q->Next!=NULL){
			printf("\t Tu vung: English :%s\t Vietnamese: %s\n",Q->Next->Data.English,Q->Next->Data.Vietnamese);
			Q=Q->Next;
		}
	}
}
