
int arr[1000];
int n;

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
	
}
int find(int m,int c)
{
	int a,b;
	if(m<0)
	{
		return 0;
	}
	if(c==2)
	{
	   return find(m-1,0);
		 	
	}
	else
	{
		printf("m= %d , val=%d \n" ,m,arr[m]);
		a=arr[m]+find(m-1,c+1);
		b=find(m-1,0);
	//	printf("m= %d , a=%d b=%d\n" ,m,a,b);
		return max(a,b);
	}

	
}


int main()
{
	int i,ans;
//	int mg[10000]
//	scanf("%d",&t);
	while(1)
	{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	ans=find(n-1,0);
	printf("%d\n",ans);
	}
return 0;	
}
