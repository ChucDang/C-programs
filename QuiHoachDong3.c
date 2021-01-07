#include<stdio.h>
#include<malloc.h>
typedef int Bang[50][100];
typedef struct{
	char ten[25];
	int TL, GT;
	int PA;
}DoVat;
DoVat *Read(int *n, int *TL){
	FILE *f=fopen("QHD_CaiBalo.inp","r");
	int i=0;
	fscanf(f,"%d",TL);
	DoVat *dsdv=(DoVat *)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%d%d%[^\n]",&dsdv[i].TL, &dsdv[i].GT, &dsdv[i].ten);
		dsdv[i].PA=0;
		i++;
		dsdv=(DoVat *)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i-1;
	fclose(f);
	return dsdv;
}
void swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp =*a;
	*a=*b;
	*b=temp;
}
void TaoBang(DoVat *dsdv,int n,int W, Bang F,Bang X){
 	int xk, yk, k;
 	int FMax, XMax, V;
// Dien hàng dau tien cua hai bang
 	for(V= 0; V<=W; V++) {
 		int temp = V/dsdv[0].TL;
 		if(temp >=1) X[0][V] = 1;
 		F[0][V] = X[0][V] * dsdv[0].GT;
 	}
// Ðien các dòng còn lai
 	for(k= 1; k<=n; k++){
 		for(V=0; V<=W; V++) {
 			FMax = F[k-1][V] ;
 			XMax = 0;
 			int temp = V/dsdv[k].TL;
 			yk=0;
 			if(temp >=1) yk=1;
 			for(xk = 1; xk<=yk; xk++)
 				if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>FMax){
 					FMax=F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
 					XMax= xk;
 				}
 			F[k][V] = FMax;
 			X[k][V] = XMax;
 		}
	}
}
void InBang(int n, int W, Bang F, Bang X){
	int V, k;
	for(k=0; k<=n; k++){
 		for(V=0; V<=W; V++){
 			printf("|%4d%2d",F[k][V], X[k][V]);
		 }
 		printf("\n");	
 	}
}
void TraBang(DoVat *dsdv, int n, int W, Bang X) {
 	int k, V;
 	V = W;
 	for(k= n; k>=0; k--) {
 		dsdv[k].PA = X[k][V];
 		V = V - X[k][V] * dsdv[k].TL;
 	}
}
void main(){
	DoVat *dsdv;
	int n,TGT = 0, TTL=0, i, TL;
	dsdv=Read(&n, &TL);
	Bang F,X;
	TaoBang(dsdv, n,TL,F,X);
	printf("Bang du lieu: \n");
	InBang(n,TL,F,X);
	printf("Danh sach truoc khi sap xep la: \n");
	printf("|    Ten do vat   |  Trong luong | Gia tri | Phuong an |\n");
	TraBang(dsdv,n,TL,X);
	for(i=0; i<=n; i++){
		TGT+=dsdv[i].PA*dsdv[i].GT;
		TTL+=dsdv[i].PA*dsdv[i].TL;
		printf("|%17s|%14d|%9d|%11d|\n", dsdv[i].ten, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
	}
	printf("X={");
	for(i=0; i<=n; i++){
		printf(" %d",dsdv[i].PA);
	}
	printf("}\n");
	printf("Tong gia tri: %d\n", TGT);
	printf("Tong trong luong: %d\n", TTL);
	free(dsdv);
}
