#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef int Key_Type;
typedef struct Node{
	Key_Type Key;
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
Tree Creat(Key_Type X, Tree Left,Tree Right){
	Tree N;
	N=(Node*)malloc(sizeof(Node));
	N->Key=X;
	N->Left=Left;
	N->Right=Right;
	return N;
}
void PreOrder(Tree T){
	if(!Empty_Tree(T)){
		printf("%d\t",T->Key);
		PreOrder(LeftChild(T));
		PreOrder(RightChild(T));
	}
}
void InOrder(Tree T){
	if(!Empty_Tree(T)){
		InOrder(LeftChild(T));
		printf("%d\t",T->Key);
		InOrder(RightChild(T));
	}
}
void PostOrder(Tree T){
	if(!Empty_Tree(T)){
		PostOrder(LeftChild(T));
		PostOrder(RightChild(T));
		printf("%d\t",T->Key);
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
Tree Search(Key_Type X,Tree T){
	Key_Type temp;
	temp=T->Key;
	if(T!=NULL) if(X==temp) return T;
	            else if(X<temp) return Search(X,LeftChild(T));
				else return Search(X,RightChild(T));
	else return NULL;
}
void InsertNode(Key_Type X, Tree *T){
	if((*T)==NULL){
		(*T)=(Node*)malloc(sizeof(Node));
		(*T)->Key=X;
		(*T)->Left=NULL;
		(*T)->Right=NULL;
	}
	else
		if((*T)->Key==X) printf("Da ton tai khoa X");
		else if((*T)->Key>X) InsertNode(X,&(*T)->Left);
		else InsertNode(X,&(*T)->Right);
}
void Read(Tree *T){
	printf("Nhap vao so nut cua cay: ");
	int n,i;
	Key_Type X;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Nhap vao khoa thu %d :",i);
		scanf("%d",&X);
		InsertNode(X,T);
	}
}
Key_Type DeleteMin(Tree *T){
	Key_Type X;
	if((*T)->Left==NULL){
		X=(*T)->Key;
		(*T)=(*T)->Right;
		return X;
	}
	else return DeleteMin(&(*T)->Left);
}
void DeleteNode(Key_Type X, Tree *T){
	if((*T)!=NULL) 
		if(X<(*T)->Key) DeleteNode(X,&(*T)->Left);
		if(X>(*T)->Key) DeleteNode(X,&(*T)->Right);
		else 	if(((*T)->Left==NULL)&&((*T)->Right==NULL)) (*T)=NULL;
				else if((*T)->Left==NULL) (*T)=(*T)->Right;
				else if((*T)->Right==NULL) (*T)=(*T)->Left;	
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

