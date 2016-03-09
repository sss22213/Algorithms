int Power_Squar(int basic,int n)
{
	if(n==0)return 1;
	//n is odd
	if(n%2==1)
	{
		int y=Power_Squar(basic,n/2-1);
		return basic*y*y;
	}
	else
	{
		int y=Power_Squar(basic,n/2);
		return y*y;
	}
}
int main()
{
	int result=Power_Squar(2,8);
	return 0;
}
