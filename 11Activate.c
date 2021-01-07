#include"TuDienBamDong.c"
int main(){
	Dictionary D;
	Element_Type X;
	Make_Null_Dictionary(&D);
	Read(&D);
//	printf("Nhap vao tu vung muon xoa:\n\tEnglish: ");fflush(stdin);gets(X.English);
//	printf("\t Vietnamese: ");fflush(stdin);gets(X.Vietnamese);
	printf("\n Ket qua tim kiem tu vung: %d \n Xoa tu vung go.\n",Member("go",D));
	Delete("go",&D);
	Print(D);
}
