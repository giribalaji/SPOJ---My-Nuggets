#include<stdio.h>

int check(long long k)
{
	int c;
	for(c=0;k;c++)
	{
		k=k&(k-1);
	}
return c;
}


int main()
{
	long long int n,k;
	int t,c;
	scanf("%d",&t);
	while(t--)	
	{
	scanf("%lld %lld",&n,&k);
	c=check(k-1);
	if(c&1)
	printf("Female\n");
	else
	printf("Male\n");
}
	return 0;
}
