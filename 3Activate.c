#include"3TuDienBangDSLK.c"
int main(){
	Dictionary D;
	Make_Null_Dic(&D);
	Read_Dic(&D);
	Print_Dic(D);
	Element_Type X;
	printf("Nhap vao mot tu can xoa: \n");
	printf("	English: ");
		gets(X.Eng);
	printf("	Vietnamese: ");
		gets(X.Viet);
	Delete_Dic(X,&D);
	Print_Dic(D);
}
