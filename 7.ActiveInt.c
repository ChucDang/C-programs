#include "7.TreeInt.c"
int main(){
	Tree T;
	Make_Null_Tree(&T);
	Read(&T);
	
	PreOrder(Root(T),T);
	PostOrder(Root(T),T);
	InOrder(Root(T),T);
}   
