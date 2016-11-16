#include<stdio.h>
int main()
{
	int i;
	unsigned long long int n,val,tmp=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
	scanf("%lld",&val);

		tmp=tmp^val;
	}
printf("%lld",tmp);
return 0;
}
