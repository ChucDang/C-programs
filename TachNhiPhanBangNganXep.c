#include "StackListlib.c"
//#include "StackLibByArray.c"
int main(){
	int n;
	Stack S,S1;
	Element_Type temp;
	Make_Null_Stack(&S);
	printf("Nhap vao mot so: ");
	scanf("%d",&n);
	if(n<2) printf("Khong phan tich duoc!");
	else{
		while(n!=0){
			temp=n%2;
			Push(temp,&S);
			n/=2;
		}
	}
	printf("Ket qua phan tich ra nhi phan la: ");
	S1=S;
	while(Empty_Stack(S1)!=1){
		printf("%d	",Top(S1));
		Pop(&S1);
	}
	
}
