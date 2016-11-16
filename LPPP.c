#include<stdio.h>
int a[1000006];
int n=0;
int dp[51][90][90][90];
int find(int arr[],int a,int b,int c,int cn)
{
	if(cn==n)
	{
		return a==b && b==c;
	}
	if(dp[a][b][c][cn]==-1)
	{
		dp[a][b][c][cn]=find(arr,a+arr[cn],b,c,cn+1)||find(arr,a,b+arr[cn],c,cn+1)||find(arr,a,b,c+arr[cn],cn+1);
	}
	return dp[a][b][c][cn];
}





int main()
{
	int len;
		int m,t=1,t1,i;
		scanf("%d",&t1);
	while(t<=t1)
	{
	memset(dp,-1,sizeof(dp[0][0][0][0])*90*90*90*51);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		m=find(a,0,0,0,0);
		if(m)
		{
		printf("Case %d: Happy Eid Day\n",t);	
		}
		else
		{
			printf("Case %d: Lov-e Pap Pap-e Polti\n",t);
		}
	t++;
}
		return 0;
		
	}
