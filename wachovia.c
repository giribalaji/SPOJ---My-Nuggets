#include<stdio.h>

int val[55];
int arr[55];

int dp[51][1003];
int max(int a, int b)
{
    return (a > b)? a : b;
}


int KS(int n,int M)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(arr[i-1]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-arr[i-1]]);
			}
		}
	}
return dp[n][M];
}


int main()
{
	int t,n,k,i,j,c=0;
	
	scanf("%d",&t);
		
	while(t--)
	{
	scanf("%d %d",&k,&n);
	memset(dp,0,sizeof(dp));
/*	for(i=0;i<=n;i++)
{
	for(j=0;j<=k;j++)
	{
		printf("%d\n",mem[i][j]);
	}
	
}*/
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i],&val[i]);
	}
	int i=KS(n,k);
	
	printf("Hey stupid robber, you can get %d.\n",i);
}
	return 0;
}


