#include "Double_List_DSLK.c"
int main(){
	Double_List DL;
	Make_Null_Double_List(&DL);
	Read_Double_List(&DL);
	Print_Double_List(DL);
}
