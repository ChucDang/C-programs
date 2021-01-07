#include "alistlib.c"
//#include"lib.c"
typedef List Stack;
void Make_Null_Stack(Stack *S){
	Make_Null_List(S);
}
Element_Type Empty_Stack(Stack S){
	return Empty_List(S);
}
void Push(Element_Type X,Stack *S){
	Insert_List(X,First(*S),S);
}
void Pop(Stack *S){
	Delete_List(First(*S),S);
}
Element_Type Top(Stack S){
	return Retrieve(First(S),S);
}
void Read_Stack(Stack *S){
	Read_List(S);
}
void Print_Stack(Stack S){
	Print_List(S);
}
void Delete_Stack(Stack *S){
	Delete_List(First(*S),S);
}

