#include<stdio.h>
#include<malloc.h>
typedef struct{
	int key;
	char ten;
}DoVat;
DoVat *Read(int *n, int *W){
	int i=0;
	FILE *f=fopen("data.txt","r");
	fscanf(f,"%d",W);
	DoVat *dsdv =(DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%d",&dsdv[i].key);
		i++;
		dsdv=(DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i-2;
	fclose(f);
	return dsdv;
}
void swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void selectionSort(DoVat *dsdv, int n){
	int i, j;
	for(i=0; i<n ;i++){
		int min_key=dsdv[i].key;
		int min_index=i;
		for(j=i+1; j<=n ; j++){
			if(dsdv[j].key<min_key){
				min_key=dsdv[j].key;
				min_index=j;
			}
		}
		swap(&dsdv[i],&dsdv[min_index]);
	}
}
void InsertSort(DoVat *dsdv, int n){
	int i, j;
	for(i=1; i<=n ; i++){
		j=i;
		while(j>0&&dsdv[j].key<dsdv[j-1].key){
			swap(&dsdv[j],&dsdv[j-1]);
			j--;
		}
	}
}
void bubbleSort(DoVat *dsdv, int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=n ;j>i; j--){
			if(dsdv[i].key>dsdv[j].key)swap(&dsdv[i], &dsdv[j]);
		}
	}
}
int findPivot(DoVat *dsdv, int i, int j){
	int k=i+1;
	while(k<=j&&dsdv[i].key==dsdv[k].key) k++;
	if(k>j) return -1;
	else if(dsdv[i].key>dsdv[k].key) return i; return k;
}
int partition(DoVat *dsdv, int i, int j, int pivot){
	int L=i;
	int R=j;
	while(L<=R){
		while(dsdv[L].key<pivot) L++;
		while(dsdv[R].key>=pivot)R--;
		if(L<R){
			swap(&dsdv[L],&dsdv[R]);
		}
	}
	return L;
}
void quickSort(DoVat *dsdv, int i, int j){
	int pivot_index=findPivot(dsdv,i,j);
	if(pivot_index!=-1){
		int pivot=dsdv[pivot_index].key;
		int k=partition(dsdv,i,j,pivot);
		quickSort(dsdv,i,k-1);
		quickSort(dsdv,k,j);
	}
}
int findPivot1(DoVat *dsdv, int i, int j){
	int k=i+1;
	while(k<=j&&dsdv[i].key==dsdv[k].key) k++;
	if(k>j) return -1;
	else if(dsdv[i].key>dsdv[k].key) return k; return i;
}
int partition1(DoVat *dsdv, int i, int j, int pivot){
	int L=i;
	int R=j;
	while(L<=R){
		while(dsdv[L].key<=pivot) L++;
		while(dsdv[R].key>pivot)R--;
		if(L<R){
			swap(&dsdv[L],&dsdv[R]);
		}
	}
	return L;
}
void quickSort1(DoVat *dsdv, int i, int j){
	int pivot_index=findPivot1(dsdv,i,j);
	if(pivot_index!=-1){
		int pivot=dsdv[pivot_index].key;
		int k=partition1(dsdv,i,j,pivot);
		quickSort1(dsdv,i,k-1);
		quickSort1(dsdv,k,j);
	}
}
void pushDown(DoVat *dsdv, int first, int last){
	int r=first;
	while(r<=(last-1)/2){
		if((last == 2*r+1)&&(dsdv[r].key> dsdv[last].key)){
			swap(&dsdv[r],&dsdv[last]);
			r=last;
		}
		else
			if((dsdv[r].key>dsdv[2*r+1].key)&&(dsdv[2*r+1].key<=dsdv[2*r+2].key)){
				swap(&dsdv[r],&dsdv[2*r+1]);
				r=2*r+1;
			}
		else
			if((dsdv[r].key>dsdv[2*r+2].key)&&(dsdv[2*r+1].key>dsdv[2*r+2].key)){
				swap(&dsdv[r],&dsdv[2*r+2]);
				r=2*r+2;
			}
		else r=last;
	}
}
void heapSort(DoVat *dsdv, int n){
	int i;
	for(i=(n-1)/2; i>=0;i--)pushDown(dsdv,i,n);
	for(i=n; i>=1; i--){
		swap(&dsdv[i],&dsdv[0]);
		pushDown(dsdv,0,i-1);
	}
	swap(&dsdv[0],&dsdv[1]);
}
void main(){
	DoVat *dsdv;
	int n, W;
	int i;
	dsdv=Read(&n, &W);
	printf("Danh sach truoc khi sap xep la: \n");
	for(i=0; i<=n ;i ++){
		printf("%d ", dsdv[i].key);
	}
	
	//selectionSort(dsdv,n);
	//InsertSort(dsdv,n);
	//bubbleSort(dsdv, n);
	//quickSort1(dsdv,0,n);
	heapSort(dsdv,n);
	printf("\nDanh sach sau :\n");
	for(i=0; i<=n ;i ++){
		printf("%d ", dsdv[i].key);
	}
}

