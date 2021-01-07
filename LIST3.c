#include"alistlib.c"
void Increase( List *L){
	Position P=First(*L),E=End(*L),Q;
	Element_Type temp;
	while(P!=E){
		Q=Next(P,*L);
		while(Q!=E){
			if(	Retrieve(P,*L)>Retrieve(Q,*L)){
				temp=L->Elements[P-1];
				L->Elements[P-1]=L->Elements[Q-1];//nho la ben trong element luon la vi tri tru di 1
				L->Elements[Q-1]=temp;
			}
			Q=Next(Q,*L);
		}
		P=Next(P,*L);
	}
}
int main(){
	Element_Type number;
	List L;
	Make_Null_List(&L);
	Read_List(&L);
	Print_List(L);
	printf("Danh sach duoc sap xep lai la: ");
	Increase(&L);
	Print_List(L);
	printf("Nhap vao mot so can chen: ");
	scanf("%d",&number);
	Insert_List(number,First(L),&L);
	Increase(&L);
	printf("Danh sach sau them: ");
	Print_List(L);
}
