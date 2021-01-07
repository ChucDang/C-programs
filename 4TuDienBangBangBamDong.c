#include<stdio.h>
#define B 10
#define Deleted -1000
#define Empty 1000
typedef int Element_Type;
typedef Element_Type Dictionary[B];
void Make_Null_Dic(Dictionary *D){
	int i=0;
	while(i<B){
		(*D)[i]=Empty;
		i++;
	}
}
int H(Element_Type X){
	return X%B;
}
int Empty_Dic(Dictionary D){
	int i=0,found=1;
	while(i<B&&found){
		if(D[i]==Empty)found=0;
		i++;
	}
	return found;
}
int Member_Dic(Element_Type X, Dictionary D){
	int P=H(X);
	int i=0,found=0;
	while(i<B&&!found&&D[P]!=Empty&&D[P]!=Deleted){
		if(D[(++P)%B]==X)found=1;
		i++;
	}
	return found;
}
void Insert_Dic(Element_Type X, Dictionary *D){
	int i=1;
	int P=H(X);
	while((i<=B)&&((*D)[P-1]!=Empty)&&(!(Member_Dic(X,*D)))&&((*D)[P-1]!=Deleted))
		i++;
	if(i>B) printf("Het cho xen.");
	else{
		(*D)[(H(X)+i)%B]=X;
	}
}
void Delete_Dic(Element_Type X, Dictionary *D){
	if(Member_Dic(X,*D)) printf("Phan tu khong nam trong D.\n");
	else{
		int i=0,j,found=0;
		int P=H(X);
		while(i<B&&!found&&(*D)[P]!=Empty&&(*D)[P]!=Deleted){
		i++;
		for(j=i;j<B;j++){
			(*D)[j]=(*D)[j+1];
		}
	}
}
}
void Read_Dic(Dictionary *D){
	printf("Nhap vao so phan tu: \n");
	int i=1,n;
	scanf("%d",&n);
	Element_Type X;
	while(i<=n){
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		Insert_Dic(X,D);
		i++;	
	}
}
void Print_Dic(Dictionary D){
	int i;
	for(i=0;i<B;i++){
		if(D[i]!=Empty&&D[i]!=Deleted) printf("\t %d\t",D[i]);
		
	}
}

