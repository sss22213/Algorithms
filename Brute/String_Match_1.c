int String_Match(char *array,int ary_len, char *str,int str_len)
{
	for(int i=0;i<ary_len-str_len;i++)
	{
		int j=0;
		while(j<str_len && array[i+j]==str[j])
		{
			j++;
		}
		if(j==str_len)return i;
	}
	return 0;
}

int main()
{
	char string[]="NOBODY_NOTICES_HIM";
	char match[]="NOT";
	int ss=String_Match(string,18,match,3);	
	return 0;
}
