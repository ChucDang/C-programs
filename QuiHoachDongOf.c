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
	*n=i-2;
	fclose(f);
	return dsdv;
}
void swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp =*a;
	*a=*b;
	*b=temp;
}
void QuiHoach(DoVat *dsdv, int n, int *W, Bang F, Bang X){
	int i;
	for(i=0; i<=*W; i++){
		X[0][i]=i/dsdv[0].TL;
		F[0][i]=X[0][i]*dsdv[0].GT;
	}
	int V, Fmax, Xmax;
	for(i=1; i<=n ; i++){
		for(V=0; V<=*W; V++){
			Fmax=F[i-1][V];
			Xmax=0;
			int yk=V/dsdv[i].TL;
			int j;
			for(j=yk; j>=0; j--){
				if(F[i-1][V-j*dsdv[i-1].TL]+j*dsdv[i-1].GT>Fmax){
					Fmax=F[i-1][V-j*dsdv[i].TL]+j*dsdv[i].GT;
					Xmax=j;
				}
			}
			F[i][V]=Fmax;
			X[i][V]=Xmax;
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
void TraBang(DoVat *dsdv,int *W, int n, Bang X){
	int i;
	int V=*W;
	for(i=n; i>=0 ;i++){
		dsdv[i].PA=X[i][V];
		V-=dsdv[i].PA*dsdv[i].TL;
	}
}
int main(){
	DoVat *dsdv;
	int W, n;
	dsdv=Read(&n, &W);
	Bang F, X;
	QuiHoach(dsdv,n,&W,F,X);
	InBang(n,W,F,X);
}
