#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Max_Length 30
typedef struct{
	char Eng[100];
	char Viet[100];
}Data;
typedef Data Element_Type;
typedef int Position;
typedef struct {
 Element_Type Elements[Max_Length];
 Position Last;
} List;
void Make_Null_List(List *L){
	(*L).Last=0;
}
int Empty_List(List L){
	return L.Last==0;
}
Position End(List L){
	return L.Last+1;
}
Element_Type Member(Element_Type X, List L){
	Position P = 1,E= End(L);
	int Found =0;
	while ((P != E) && (!Found))
		if(strcmp(L.Elements[P].Eng,X.Eng)!=0) Found=1;
		else P=P+1;
		if((L.Elements[E-1].Eng,X.Eng)!=0) P=E+1;
	return L.Elements[P];
}
void Insert_List(Element_Type X, Position P, List *L){
	Position i;
	if((*L).Last==Max_Length)
		    printf("\n Danh sach day roi nhe");
	else {
			for(i=(*L).Last;i>=P;i--)
		        (*L).Elements[i]=(*L).Elements[i-1];
		    (*L).Last++;
		    (*L).Elements[P-1]=X;
	     }
}
void Read_List(List *L){
	int number;
	int i;
	Element_Type X;
	printf("Nhap vao so luong phan tu cua danh sach: ");
	scanf("%d",&number);
	for(i=1;i<=number;i++){
		fflush(stdin);
		printf("Nhap tu vung: ");
		gets(X.Eng);
		fflush(stdin);
		printf("Nhap nghia tieng viet: ");
		gets(X.Viet);
		Insert_List(X,End(*L),L);
	}
}
void Print_List(List L){
	Position P=1, E=End(L);
	while(P!=E){
		printf("Eng:  %s Viet:  %s\n",L.Elements[P-1].Eng,L.Elements[P-1].Viet);
		P=P+1;
	}
}
void Delete_List(Element_Type X,List *L){
	Position P,Q;
	for(P=0;P<End(*L);P++){
		if(strcmp((*L).Elements[P].Eng,X.Eng)==0){
			for(Q=P;Q<End(*L);Q++) (*L).Elements[P]=(*L).Elements[P+1];
		}
	}
	(*L).Last--;
}
int main(){
	List L;
	Make_Null_List(&L);
	Read_List(&L);
	Print_List(L);
}
