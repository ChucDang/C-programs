#include"10.BSTKhachHang.c"
int main(){
	BST T;
	Make_Null(&T);
	printf("Nhap vao so luong khach hang: ");
	int i,n;
	scanf("%d",&n);
	Read(n,&T);
	printf("\nNhap vao ID can tim: \n");
	int ID1;
	scanf("%d",&ID1);
	if(Search(ID1,T)==NULL) printf("\nID chua duoc nhap\n");
	else Print(Search(ID1,T)->Data);
}
