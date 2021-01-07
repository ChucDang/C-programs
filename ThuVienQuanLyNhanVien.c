#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct{
	char Name[40];
	int ID;
	int Hrsworked;
	float Payhrs;
} Employee;
typedef Employee Element_Type;
typedef struct Node{
	Element_Type Element;
	struct Node* Next;
}Node;
typedef Node* Position;
typedef Position List;
Position First(List L){
	return L;
}
Position End(List L){
	Position P=First(L);
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}
 
void Make_Null_List(List *L){
	(*L)=(struct Node*)malloc(sizeof(struct Node));
	(*L)->Next=NULL;
}
void Insert(Element_Type X,List *L){
	Position P=End(*L);
	Position T=End( *L)->Next;
	T=(Node*)malloc(sizeof(Node));
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}
void Read_List(List *L){
	int n,i=1,IDnumber;
	Position P=First(*L);
	Element_Type Q;
	printf("Nhap vao so luong nhan vien: \n");
	scanf("%d",&n);
	fflush(stdin);
	while(i<=n){
		printf("Thong tin nhan vien thu %d :\n",i);
		printf("	ID: ");scanf("%d",&Q.ID);
		fflush(stdin);
		Position P=First(*L);
		int found=0;
	while(P->Next!=NULL){
		if((P->Next->Element.ID)==(Q.ID)){
			found=1;
			break;
		}
		P=P->Next;
	}
	if(found==1) printf(" ID da trung! Khong the them. \n");
	else{
		printf("	Ten: ");
		gets(Q.Name);	
		fflush(stdin);
		printf("	So gio lam viec : ");scanf("%d",&Q.Hrsworked);
		fflush(stdin);
		printf("	Luong moi gio : ");scanf("%f",&Q.Payhrs);
		fflush(stdin);
		Insert(Q,L);
		i++;
	}
}
}
Position Find_ID(int a, List L){
	Position P=First(L);
	int found=0;
	while(P->Next!=NULL){
		if(P->Next->Element.ID==a){
			found=1;
			break;
		}
		else{
			P=P->Next;
		}
	}
	if(found==1) printf("Da tim thay! \n");
	else 
	printf("Khong tim thay! \n");
	return P;
}
void Print_Employee(Position P,List L){
	float h,t,tienluong;
	h=(P->Next->Element.Hrsworked);
	t=(P->Next->Element.Payhrs);
	tienluong=h*t;
	printf("Thong tin nhan vien vi tri thu %d\n",P);
	printf(" Ten : %s  Ma nhan vien: %d Tien luong: %f \n",P->Next->Element.Name, P->Next->Element.ID, tienluong);
}
void Print_List(List L){
	Position P=First(L);
	int i=1;
	while(P->Next!=NULL){
		printf("Thong tin nhan vien thu %d :\n",i);
		printf("	Ten: %s",P->Next->Element.Name);
		printf("	ID: %d ",P->Next->Element.ID);
		printf("	So gio lam viec : %d",P->Next->Element.Hrsworked);
		printf("	Luong moi gio : %f ",P->Next->Element.Payhrs);
		i++;
		P=P->Next;
	}
}
