#include"9.FindBinary.c"
int main(){
	Tree T,T1,T2 ;
	Make_Null_Tree(&T);
	Read(&T);
	printf("Danh sach in tuan tu la: \n");
	PreOrder(T);
	printf("\nCay in trung tu la: \n");
	InOrder(T);
	printf("\n Cay in hau tu la: \n");
	PostOrder(T);
	printf("\nXoa 1 vao cay:\n");
	DeleteNode(1,&T);
	printf("\nCay in trung tu la: \n");
	InOrder(T);
	printf("\n Cay in hau tu la: \n");
	PostOrder(T);
}
