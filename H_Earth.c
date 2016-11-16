#include<stdio.h>

int main()
{
	int n,p;
	while(1)
	{
		scanf("%d %d",&n,&p);
	float p1=p/100.00;
	float p2=1-(p/100.00);
	float dp[105];
	dp[0]=0;
	dp[1]=0;
	dp[2]=p1;
	dp[3]=p2;
	int i;

	for(i=4;i<=n;i++)
	{
		dp[i]=dp[i-2]*p1+dp[i-3]*p2;
	}

	printf("%f\n",dp[n]);
}
return 0;
}

