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
	int *Temp1;
	Temp1=(int*)malloc(4*sizeof(int));
        int *Temp2;
	Temp2=(int*)malloc(4*sizeof(int));
        int *Temp3;
	Temp3=(int*)malloc(4*sizeof(int));
	if(Temp1==NULL || Temp2==NULL || Temp3==NULL)
	{
		perror("Memory leak");
		exit(1);
	}
	//if return A,free(Temp1) will free array.
	//So need to return Dynamic memory.
	if(n==1)
	{
		memcpy(Temp1,A,4*sizeof(int));
		return Temp1;
	}
	//n is even
	if(n%2==0)
	{
		memcpy(Temp1,fiber2(n/2),4*sizeof(int));
		doub_Mat_mul(Temp1,4,Temp1,4,Temp2,4);
		free(Temp1);
		free(Temp3);
		return Temp2;
	}
	//n is odd
	else
	{
		memcpy(Temp1,fiber2((n-1)/2),4*sizeof(int));
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
	A=(int*)malloc(4*sizeof(int));
	if(argv<2)
	{
		perror("Please input parameter");
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
