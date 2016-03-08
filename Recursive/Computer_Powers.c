int Power(int basic,int n)
{
	if(n==0)return 1;
	return Power(basic,n-1)*basic;
}
int main()
{
	int result=Power(2,5);
	return 0;
}
