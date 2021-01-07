#include "plistlib.c"
int main(){
	List L;
	Make_Null_List(&L);
	Read_List(&L);
	Position Q=First(L),K,R;
	printf("Danh sach da nhap la: ");
	Print_List(L);
	while(Next(Q,L)!=NULL){
		R=Next(Q,L);
		while(Next(R,L)!=NULL){
			if(Retrieve(R,L)==Retrieve(Q,L)){
				K=Previous(R,L);
				Delete_List(R,&L);
				R=K;
			}
			else
			R=Next(R,L);
		}
		Q=Next(Q,L);
	}
	printf("Danh sach da don gian la: ");
	Print_List(L);
}
	
