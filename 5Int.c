#include"5.TuDiemBamMo.c"
int main(){
	Dictionary D;
	Make_Null_Dic(&D);
	Element_Type X;
	Read(&D);
	Delete(5,&D);
	Print(D);
}
