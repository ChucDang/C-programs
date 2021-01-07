#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef char Element_Type;
typedef struct Node{
	Element_Type Data;
	struct Node*Left;
	struct Node*Right;
}Node;
typedef Node*Tree;
void Make_Null_Tree(Tree *T){
	(*T)=NULL;
}
bool Empty_Tree(Tree T){
	return T==NULL;
}
Tree LeftChild(Tree n){
	if(n!=NULL) return n->Left;
	else return NULL;
}
Tree RightChild(Tree n){
	if(n!=NULL) return n->Right;
	else return NULL;
}
bool isLeaf(Tree n){
	return ((n!=NULL)&&(n->Left==NULL)&&(n->Right==NULL));
}
Tree Creat(Element_Type X, Tree Left,Tree Right){
	Tree N;
	N=(Node*)malloc(sizeof(Node));
	N->Data=X;
	N->Left=Left;
	N->Right=Right;
	return N;
}
void PreOrder(Tree T){
	if(!Empty_Tree(T)){
		printf("%c\t",T->Data);
		PreOrder(LeftChild(T));
		PreOrder(RightChild(T));
	}
}
void InOrder(Tree T){
	if(!Empty_Tree(T)){
		InOrder(LeftChild(T));
		printf("%c\t",T->Data);
		InOrder(RightChild(T));
	}
}
void PostOrder(Tree T){
	if(!Empty_Tree(T)){
		PostOrder(LeftChild(T));
		PostOrder(RightChild(T));
		printf("%c\t",T->Data);
	}
}
int Number_Node(Tree T){//Chu y phan de quy nay
	if(Empty_Tree(T)) return 0;
	return Number_Node(T->Left)+Number_Node(T->Right)+1;
}
int Max(int x, int y){
	return (x>y)?x:y;
}
int TreeHeight(Tree T){
	int height=0;
	if(!Empty_Tree(T)){
		if(isLeaf(T)) height=0;
		else height=Max(TreeHeight(LeftChild(T)),TreeHeight(RightChild(T)))+1;
	}
	return height;
}
int LeafNode(Tree T){
	int count=0;
	if(!Empty_Tree(T)){
		if(isLeaf(T)) count++;
		else count= LeafNode(LeftChild(T))+LeafNode(RightChild(T));
	}
	return count;
}
/*void CreateTree(int locate, Tree *T){
	N=(Node*)malloc(sizeof(Node));
	if(locate==1){//them vao trai;
		T->Left=N;
	}
	N->Left=NULL;
	N->Right=NULL;
}
void ReadTree(Tree *T){
	printf("Nhap vao so nut: ");
	int n;
	scanf("%d",&n);
	if(Empty_Tree(T)){
		Tree N;
		
	}
	bool ContLeft=True;
	while(ContLeft){
		T->Left
		while(T->Ri)
	}
}*/
