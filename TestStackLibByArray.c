#include"StackLibByArray.c"//không có khai báo thu vien alistlib.c
int main(){
	Stack S,S1;
	Make_Null_Stack(&S);
	Read_Stack(&S);
	S1=S;
	while(Empty_Stack(S1)!=1){
		printf("%d	",Top(S1));
		Pop(&S1);
	}
}

