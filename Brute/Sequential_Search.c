int Sequential_Search(unsigned char* array,int len,int goal)
{
	int i=0;
	for(;i<len;i++)
	{
		if(array[i]==goal)
		break;
	}
	return i;	

}

int main()
{
	unsigned char source[5]={25,20,189,61,15};
	int output=Sequential_Search(source,5,61);
	return 0;
}
