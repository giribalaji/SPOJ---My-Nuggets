#include<stdio.h>
#define INT_MAX 50000 
int min(int x, int y)
{
   if (x < y)
      return x ;
   else
      return y;
}
int main()
{
	int dp[1010];
	int t,n=1,i,pn,rep;
dp[0]=0;
for(i=1;i<17;i++)	
{
	dp[i]=INT_MAX;
	for(n=1;n<=i;n++)
	{
		pn=pow(n,2);
		if(pn<=i)
		{
		//	dp[i]=1+min(min(dp[i-pn],dp[i]),dp[i%pn]);
	
		//	dp[i]=1+min(min(dp[i-pn],dp[i]),rep);
			dp[i]=1+min(dp[i-pn],dp[i]);
			if(i%pn==0)
				
				{
				rep=i/pn;
				rep=rep;
				printf("Total = %d rep = %d\n",i,rep);
			}
			else
				rep=INT_MAX;
			
		
			dp[i]=min(dp[i],rep);
			printf("Final = %d DP = %d\n",i,dp[i]);
			//dp[i]=1+min(dp[i-pn],dp[i]);
		}
		else
			break;
	}
	
}
	
	
	scanf("%d",&t);
 
 while(t--)
 {
 	scanf("%d",&n);
 	printf("%d\n",dp[n]);
 }
	return 0;
}
