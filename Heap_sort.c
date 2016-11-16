


void heapify(int a[],int i, int len)
{
//	printf(" is %d & %d\n",i,a[i]);
	int large=i,left,right;
	left=2*i+1;
	right=2*i+2;
	printf("cuurent node is %d & left =  %d , right = %d\n",a[i],a[left],a[right]);
	if(left<len&&a[left]>a[large])
	{
		large=left;
	}
	if(right<len&&a[right]>a[large])
	{
		large=right;
	}
	
	if(large!=i)
	{
		int t=a[large];
		a[large]=a[i];
		a[i]=t;
		heapify(a,large,len);
	}

}


void build_heap(int a[],int len)
{
	int i;
	for(i=len/2-1;i>=0;i--)
	{
		heapify(a,i,len);
	}
}
int a[1000006];

int main()
{
	int len;
		int m,n,t=0,i;
//	int mg[10000]
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
			scanf("%d",&a[i]);
		}
		build_heap(a,len);
		printf("%d\n",a[0]);
		for(i=0;i<len;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
		a[0]=1;
		heapify(a,0,len);
		printf("%d\n",a[0]);
		for(i=0;i<len;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
/*		t=t+a[0];
		a[0]=a[0]-1;
		for(i=1;i<n;i++)
		{
			heapify(a,0,len);
			t=t+a[0];
	//	printf("%d",a[0]);
			a[0]=a[0]-1;
		}
printf("%d\n",t);*/
return 0;
}
