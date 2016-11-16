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
	while(1)
	{
	
	scanf("%lld %lld",&n,&k);
	c=check(k);
	if(n%2==1)
	{
	if(!(c&1))
	printf("blue\n");
	else
	printf("red\n");
	}
	else
	{
	if((c&1))
	printf("blue\n");
	else
	printf("red\n");	
	}
	}
	return 0;
}
