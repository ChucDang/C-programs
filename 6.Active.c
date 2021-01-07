#include"6.BamMoTuDien.c"
int main(){
	Dictionary D;
	Make_Null_Dic(&D);
	Read(&D);
	char s[10];
	fflush(stdin);
	printf("Nhap tu tieng anh can xoa: ");
	gets(s);
	Delete(s,&D);
	Print(D);
}
