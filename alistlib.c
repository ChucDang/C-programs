#include<stdio.h>
#include<conio.h>
#define Max_Length 30
typedef int Element_Type;
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
Position First(List L){
	return 1;
}
Position End(List L){
	return L.Last+1;
}
Position Next(Position P, List L){
	return P+1;
}
Position Previous(Position P, List L){
	return P-1;
}
Element_Type Retrieve(Position P, List L){
	return L.Elements[P-1];
}
Position Locate(Element_Type X, List L){
	Position P = First(L),E= End(L);
	int Found =0;
	while ((P != E) && (!Found))
		if(Retrieve(P,L)==X) Found=1;
		else P=Next(P,L);
	return P;
}
void Insert_List(Element_Type X, Position P, List *L){
	Position i;
	if((*L).Last==Max_Length)
		    printf("\n Danh sach day roi nhe, Ahihi do ngoc");
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
		scanf("%d",&X);
		Insert_List(X,End(*L),L);
	}
}
void Print_List(List L){
	Position P=First(L), E=End(L);
	while(P!=E){
		printf("%d",Retrieve(P,L));
		P=Next(P,L);
	}
}
void Delete_List(Position P,List *L){
	for(P;P<End(*L);P=Next(P,*L)){
		(*L).Elements[P-1]=(*L).Elements[P];
	}
	(*L).Last--;

}
int main(){
	List L;
	Make_Null_List(&L);
	Read_List(&L);
	Print_List(L);
	printf("%d",End(L));
}
