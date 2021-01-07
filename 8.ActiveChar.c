#include"8.CayNhiPhan.c"
int main(){
	Tree T,T1,T2 ;
	Make_Null_Tree(&T);
	T1=Creat('B',Creat('D',NULL,NULL),Creat('E',Creat('H',NULL,NULL),NULL));
	T2=Creat('C',Creat('F',NULL,Creat('I',NULL,NULL)),Creat('G',NULL,NULL));
	T=Creat('A',T1,T2);
	printf("Danh sach in tuan tu la: \n");
	PreOrder(T);
	printf("\nCay in trung tu la: \n");
	InOrder(T);
	printf("\n Cay in hau tu la: \n");
	PostOrder(T);
	printf("\nSo nut tren cay la: %d\n",Number_Node(T));
	printf("Chieu cao cua cay: %d\n",TreeHeight(T));
	printf("So nut la tren cay la: %d",LeafNode(T));
}
