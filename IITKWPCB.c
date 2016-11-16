
int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}


int main()
{

	long long int t,n,i,j;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
	for(i=n/2;i>=1;i--)	
	{
	//	printf(" i = %d \n",i);
		j=gcd(i,n);
		if(j==1)
		{
			printf("%lld \n",i);
			break;
		}
	}
}
return 0;	
}
