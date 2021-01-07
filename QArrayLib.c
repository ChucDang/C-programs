#include <stdio.h>
#include <conio.h>
#define Max_Length 5
typedef int Element_Type;
typedef struct
{
	Element_Type Elements[Max_Length];
	int Front, Rear;
} Queue;
void Make_Null_Queue(Queue *Q)
{
	(*Q).Front = -1;
	(*Q).Rear = -1;
}
int Empty_Queue(Queue Q)
{
	return Q.Front == -1;
}
int Full_Queue(Queue Q)
{
	return (Q.Rear - Q.Front + 1) == Max_Length;
}
void En_Queue(Element_Type X, Queue *Q)
{
	if (Full_Queue(*Q))
		printf("Queue is full!");
	else
	{
		if (Empty_Queue(*Q))
			(*Q).Front = 0;
		else
			(*Q).Rear = (*Q).Rear % Max_Length;
		/*if(Q->Rear==Max_Length-1){
			int k=(*Q).Front,h=(*Q).Rear,i;
			for(i=k;i<=h;i++){
				(*Q).Elements[i-k]=(*Q).Elements[i];
			}
			(*Q).Rear=(*Q).Rear-(*Q).Front;
			(*Q).Front=0;
		}
	}*/
		(*Q).Rear++;
		(*Q).Elements[(*Q).Rear] = X;
	}
}
void De_Queue(Queue *Q)
{
	if ((*Q).Front == (*Q).Rear)
		Make_Null_Queue(Q);
	else
		(*Q).Front++;
}
Element_Type Front(Queue Q)
{
	return Q.Elements[Q.Front];
}
void Read_Queue(Queue *Q)
{
	int amount, X;
	printf("Nhap vao so luong phan tu trong Queue: ");
	scanf("%d", &amount);
	while (amount > 0)
	{
		scanf("%d", &X);
		En_Queue(X, Q);
		amount--;
	}
}
