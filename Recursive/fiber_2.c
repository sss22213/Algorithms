#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//two*two phalanx mul
void doub_Mat_mul(int *A,int lenA,int *B,int lenB,int *C,int lenC)
{
	if(lenC<4)
	{
		perror("MatrixC is too short");
		exit(1);
	}
	C[0]=A[0]*B[0]+A[1]*B[2];
	C[1]=A[0]*B[1]+A[1]*B[3];
	C[2]=A[2]*B[0]+A[3]*B[2];
	C[3]=A[2]*B[1]+A[3]*B[3];
}	
int *fiber2(int n)
{
	static int A[4]={0,1,1,1};
	//if return A,free(Temp1) will free array.
	//So need to return Dynamic memory.
	if(n==1)
	{
		int *Temp0;
		Temp0=(int*)malloc(4*sizeof(int));
		memcpy(Temp0,A,4*sizeof(int));
		return Temp0;
	}
	int *Temp1;
	int *Temp2;
	Temp2=(int*)malloc(4*sizeof(int));
	if(Temp2==NULL)
        {
		perror("Memory leak");
               	exit(1);
	}
	//n is even
	if(n%2==0)
	{
		Temp1=fiber2(n/2);
		doub_Mat_mul(Temp1,4,Temp1,4,Temp2,4);
		free(Temp1);
		return Temp2;
	}
	//n is odd
	else
	{
		int *Temp3;
		Temp3=(int *)malloc(4*sizeof(int));
                if(Temp3==NULL)
                {
                        perror("Memory leak");
                        exit(1);
                }
		Temp1=fiber2((n-1)/2);
                doub_Mat_mul(Temp1,4,Temp1,4,Temp2,4);
               	doub_Mat_mul(Temp2,4,A,4,Temp3,4);
 	       	free(Temp1);
                free(Temp2);
                return Temp3;
	}
	
}
int main(int argv,char *argc[])
{
	int *A;
	if(argv<2)
	{
		perror("Please input parameter");
		exit(1);
	}
	if(atoi(argc[1])<1)
	{
		perror("N need to more than 0");
		exit(1);
	}
	A=fiber2(atoi(argc[1]));	
	for(int i=0;i<4;i++)
	{
		printf("%d",A[i]);
	}
	free(A);
	printf("\n");
	return 0;
}
