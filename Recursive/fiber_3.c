#include <stdio.h>
#include <stdlib.h>
typedef struct _items items;
typedef struct _items
{
	int A[4];
	items *next;

}items;

items *newnode(items* head)
{
	items *node;
	node=(items*)malloc(sizeof(items));
	if(node==NULL)
	{
		perror("Memory leak");
		exit(1);
	}
	head->next=node;
	node->next=NULL;
	return node;
}
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
items *fiber2(int n,items *head,items *tail)
{
	static int A[4]={0,1,1,1};
	if(n==1)return A;
	items *node=newnode(head,tail);
	if(node->next==NULL)
	{
		perror("the node is tail");
		exit(1);
	}
	if(node==NULL)
	{
		perror("Memory leak");
		exit(1);
	}

	//n is even
	if(n%2==0)
	{
		fiber2(n/2,head,tail);
		doub_Mat_mul(Temp1,4,Temp1,4,Temp2,4);
		return node;
	}
	//n is odd
	else
	{
		fiber2((n-1)/2,head,tail);
                doub_Mat_mul(Temp1,4,Temp1,4,Temp2,4);
               	doub_Mat_mul(Temp2,4,A,4,Temp3,4);
                return node;
	}
	
}
int main(int argv,char *argc[])
{
	items *head;
	head=(items*)malloc(sizeof(items));
	itmes *tail;
	tail=(items*)malloc(sizeof(items));
	if(head==NULL || tail==NULL)
	{
		perror("memory leak");
		exit(1);
	}
	fiber2(5,head,tail);
	printf("\n");
	return 0;
}
