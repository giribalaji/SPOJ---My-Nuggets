#include<stdio.h>

int dp[10002];

int arr[10002];
//int arr[]={10 };
//int arr[]={1,2,3,4,5};
int arr[]={1,3,6,4,5};
int n = sizeof(arr)/sizeof(arr[0]);

//int arr[1002];
//int mem[1002][1002]={0};
int max(int a, int b)
{
    return (a > b)? a : b;
}


int farida(n)
{
	if(n<0)
		return 0;
	return max(arr[n]+farida(n-2),farida(n-1));
}


int farida_dp(n)
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
		scanf("%d",&arr[i]);

	printf("Case %d: %d\n",c,farida_dp(n));
}

	
	
	
	return 0;
}
