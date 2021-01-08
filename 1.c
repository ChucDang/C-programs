#include "1VecToBitAsscii.c"
int main()
{
	Set A;
	Make_Null_Set(&A);
	printf("\nNhap vao tap hop A:");
	Read_Set(&A);
	Print_Set(A);
	printf("In ra chuc dep trai");
}
