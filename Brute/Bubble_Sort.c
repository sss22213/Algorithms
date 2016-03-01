void Swap(int *a,int *b)
{
	int Temp=*a;
	*a=*b;
	*b=Temp;
}

void Bubble_Sort(int *array,int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				Swap(&array[j],&array[j+1]);
			}
		}
	}


}

int main()
{
	int A[7]={89,45,68,90,29,34,17};
	Bubble_Sort(A,7);
	return 0;
}
