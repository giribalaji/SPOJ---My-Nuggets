#include<stdio.h>


long int arr[502];
long int dp[502][2000003];
int max(int a, int b)
{
    return (a > b)? a : b;
}




int KS(n,M)
{

int i,j;
//int mem[n+1][M+1];
for(i=1;i<=n;i++)
{
	for(j=1;j<=M;j++)
	{
		
	
	
	if(arr[i-1]>j)
		dp[i][j]=dp[i-1][j];
	else
		dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i-1][j-arr[i-1]]);

	
	}
}
	return dp[n][M];
}



int main()
{
	int t,n,k,i,j,c=0;
	//int arr[1002];

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
		scanf("%d",&arr[i]);
	}
	int i=KS(n,k);
	printf("%d\n",i);

	return 0;
}
