#include<stdio.h>

long long int dp[10002];

long long int arr[10002];



long long int max(long long int a, long long int b)
{
    return (a > b)? a : b;
}


int farida(n)
{
	if(n<0)
		return 0;
	return max(arr[n]+farida(n-2),farida(n-1));
}


long long int farida_dp(n)
{
	dp[1]=arr[0];
	dp[2]=max(arr[0],arr[1]);
	int i;
	for(i=3;i<=n;i++)
	{
		dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
	}
	return dp[n];
}
int main()
{
	
	int t,n,k,i,j,c=0;
	//int arr[1002];
	scanf("%d",&t);
	
	while(t--)
	{
	memset(dp,0,sizeof(dp));
	c++;
	scanf("%d" ,&n);
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);

	printf("Case %d: %lld\n",c,farida_dp(n));
}


	return 0;
}
