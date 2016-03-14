#include <stdio.h>
#include <stdlib.h>
int fiber1(int n)
{
	if(n==0)return 0;
	else if(n==1)return 1;
	return fiber1(n-2)+fiber1(n-1);
}
int main()
{
	int result=fiber1(10);
	return 0;
}
