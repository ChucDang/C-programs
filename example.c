#include "alistlib.c"
int main(){
	List L;
	Make_Null_List(&L);
	Read_List(&L);
	Print_List(L);
}
