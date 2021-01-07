#include<stdio.h>
#define Max_Length 100
#define Null -1
typedef int Element_Type;
typedef int Node;
typedef struct{
	Element_Type Data[Max_Length];
	Node Parent[Max_Length];
	int Max_Node;
}Tree;
Tree T;
void Make_Null_Tree(Tree *T){
	(*T).Max_Node=0;
}
int Empty_Tree(Tree T){
	return T.Max_Node==0;
}
Node Parent(Node n,Tree T){
	if(Empty_Tree(T)||n>T.Max_Node-1||n<0)return Null;
		return T.Parent[n];
	}
Element_Type Label_Node(Node n,Tree T){
	if(n>=0||n<T.Max_Node) return T.Data[n];
	return Null;//neu ba me cua n khong hop le thi tra ve null
}
Node Root(Tree T){
	if(!Empty_Tree(T)) return 0;return Null;
}
Node Left_Most_Child(Node n,Tree T){
	Node i;
	if(n<0||n>=T.Max_Node)return Null;//Kiem tra n hop le hay khong;
	i=n+1;
	while(i<=T.Max_Node-1){
		if(T.Parent[i]==n) return i;
		else i++;
	}
	return Null;
}
Node Right_Sibling(Node n, Tree T){
	if(n<0||n>T.Max_Node) return Null;
	if(T.Parent[n+1]==T.Parent[n]) return (n+1);
	return Null;
}
void PreOrder(Node n, Tree T){//duyet tien thu tu
		printf(" %c ",Label_Node(n,T));
		Node i=Left_Most_Child(n,T);
		while(i!=Null){
			PreOrder(i,T);
			i=Right_Sibling(i,T);
		}
}
void InOrder(Node n, Tree T){
	Node i=Left_Most_Child(n, T);
	printf(" %c ",Label_Node(n,T));
	while(i!=Null){
		InOrder(i,T);
		i=Right_Sibling(i,T);
	}
}
void PostOrder(Node n, Tree T){
	Node i=Left_Most_Child(n, T);
	while(i!=Null){
		PostOrder(i,T);
		i=Right_Sibling(i, T);
	}
	printf(" %c ",Label_Node(n,T));
}
void Read(Tree *T){
	int i;
	do{
		printf("Nhap vao so nut: ");
		scanf("%d",&(*T).Max_Node);
	}while((*T).Max_Node<1||(*T).Max_Node>Max_Length);
	printf("Nhap nhan cua nut goc: ");
	fflush(stdin);
	scanf("%c",&(*T).Data[0]);
	(*T).Parent[0]=Null;
	for(i=1;i<(*T).Max_Node;i++){
		printf("Nhap cha cua nut %d(kieu int) : ",i);
		scanf("%d",&(*T).Parent[i]);
		printf("Nhap nhan cua nut %d (kieu nhan)",i);
		fflush(stdin);
		scanf("%c",&(*T).Data[i]);
	}
}

