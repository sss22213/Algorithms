int String_Match(char *array,int ary_len, char *str,int str_len)
{
	for(int i=0;i<ary_len-str_len;i++)
	{
		int flag=0;
		for(int j=0;j<str_len;j++)
		{
			if(array[i+j]!=str[j])
			{
				break;
			}
			else
			{
				flag++;
			}
			if(flag==str_len)
			{
				return i;
			}
		}
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
