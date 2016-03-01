
void Swap(int *a,int *b)
{
	int Temp=*a;
	*a=*b;
	*b=Temp;
}

void Selection_sort(int *array,int len)
{
	for(int i=0;i<len;i++)
	{
		int Min=i;
		for(int j=i+1;j<len;j++)
		{
			if(array[Min]>array[j])
			{
				Min=j;
			}
		}
		Swap(&array[Min],&array[i]);
	}


}

int main()
{
	int A[7]={1,225,23,22,489,323,89};
	Selection_sort(A,7);
	return 0;
}
