#include "4TuDienBangBangBamDong.c"
int main(){
	Dictionary D;
	Make_Null_Dic(&D);
	Insert_Dic(3,&D);
	Insert_Dic(3,&D);
	Insert_Dic(2,&D);
	Print_Dic(D);
	Delete_Dic(2,&D);
	Print_Dic(D);
	/*Read_Dic(&D);
	Delete_dic()*/
}
