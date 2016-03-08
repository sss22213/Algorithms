int Binary_Sum(int *A,int i,int n)
{
	if(n==1)return A[i];
	//n Mod is not 0
	if(n%2!=0)
	{
		return Binary_Sum(A,i,n/2+1)+Binary_Sum(A,i+n/2+1,n/2);
	}
	else
	{
		return Binary_Sum(A,i,n/2)+Binary_Sum(A,i+n/2,n/2);
	}
}

int main()
{
	int A[10]={0,1,2,3,4,5,6,7,8,9};
	int result=Binary_Sum(A,0,10);
	return 0;
}

