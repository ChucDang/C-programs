#include"alistlib.c"
int main(){
	List L;
	Make_Null_List(&L);
	Read_List(&L);
	Print_List(L);
	Element_Type X;
	fflush(stdin);
	printf("Nhap tu vung muon xoa: ");
	gets(X.Eng);
	fflush(stdin);
	printf("Nhap vao nghia tieng viet: ");
	gets(X.Viet);
	Delete_List(X,&L);
	Print_List(L);
	printf("Nhap tu vung can them: ");
	gets(X.Eng);
	fflush(stdin);
	printf("Nhap vao nghia tieng viet: ");
	gets(X.Viet);
	Insert_List(X,End(L),&L);
	Print_List(L);
}
