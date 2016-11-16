#include<stdio.h>

unsigned long long int dp[65][10];

void fun()
{
	unsigned long long int sum,sum1;
	int i,j,k;
	for(i=2;i<65;i++)
	{
		sum1=0;
		for(j=0;j<10;j++)
		{
		sum=0;
		for(k=j;k<10;k++)
		{
			
			sum=sum+dp[i-1][k];
	//printf("j= %d .. k=%d  sum=%llu  =  %llu\n",j,k,sum,dp[i-1][k]);
	
		}
		dp[i][j]=sum;
		sum1=sum1+sum;
		//printf("%d .. %d  =  %llu\n",i,j,sum1);
	}
	dp[i][j]=sum1;
	//	printf("%d .. %d  =  %llu\n",i,j,sum1);
}
	
	
}


int main()
{
	int t,n,k,i,j,c=0;
	//int arr[1002];
	scanf("%d",&t);
memset(dp,0,sizeof(dp));
	for(j=0;j<=9;j++)
	{
		dp[1][j]=1;
	//	printf("%d\n",dp[1][j]);
	}
	
	fun();
	
	
	while(t--)
	{
	c++;
	scanf("%d %d",&k,&n);


	printf("%d %llu\n",k,dp[n][10]);
}
	return 0;
}
