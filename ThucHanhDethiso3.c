#include"ThuVienQuanLyNhanVien.c"
int main(){
	List L;
	int id;
	Make_Null_List(&L);
	Read_List(&L);
	Print_List(L);
	printf("Nhap vao mot Id: ");
	scanf("%d",&id);
	if(	End(L)->Element.ID==id){
		printf("Da tim thay: \n ");
		printf("	Ten: %s",End(L)->Element.Name);
		printf("	ID: %d",End(L)->Element.ID);
		printf("	So gio lam viec : %d",End(L)->Element.Hrsworked);
		printf("	Luong moi gio : %f",End(L)->Element.Payhrs);
	}
	else{
		if(Find_ID(id,L)!=End(L)){
		printf("Da tim thay: \n ");
		printf("	Ten: %s",Find_ID(id,L)->Next->Element.Name);
		printf("	ID: %d",Find_ID(id,L)->Next->Element.ID);
		printf("	So gio lam viec : %d",Find_ID(id,L)->Next->Element.Hrsworked);
		printf("	Luong moi gio : %f",Find_ID(id,L)->Next->Element.Payhrs);
		}
	}
}
