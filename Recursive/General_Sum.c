int LinearSum(int *A,int n)
{
	if(n==1)return A[0];
	return LinearSum(A,n-1)+A[n-1];
}
int main()
{
	int A[10]={1,2,3,4,5,6,7,8,9,0};
	int result=LinearSum(A,10);
	return 0;
}
