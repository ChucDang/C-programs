#include<stdio.h>
#define Max_Length 100
typedef int Element_Type;
typedef struct{
	Element_Type Elements[Max_Length];
	int Top_Idx ;//Top_Idx se lay gia tri cua chi so o dinh
} Stack;
void Make_Null_Stack(Stack *S){
	(*S).Top_Idx=Max_Length;
}
int Empty_Stack(Stack S){
	return S.Top_Idx==Max_Length;
}
int Full_Stack(Stack S){
	return S.Top_Idx==0;
}
Element_Type Top(Stack S){
	return S.Elements[S.Top_Idx];
}
void Pop(Stack *S){
		(*S).Top_Idx++;
}
void Push(Element_Type X, Stack *S){
	if(Full_Stack(*S)==1) printf("Stack da day!");
	else{
		(*S).Top_Idx--;
		(*S).Elements[(*S).Top_Idx]=X;//S.Elements[--S.Top_Idx]=X;
	}
}
void Read_Stack(Stack *S){
	Element_Type amount, X;
	printf("nhap vao so luong phan tu: ");
	scanf("%d",&amount);
	while(amount!=0){
		scanf("%d",&X);
		Push(X, S);
		amount--;
	}
}


