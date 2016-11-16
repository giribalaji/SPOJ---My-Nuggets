#include<stdio.h>
#include<limits.h>
#define R 5
#define C 5
#define INT_MAX 50000 

int a[111] [111];
int dp[111][111];
 int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
 
 
 
 
 int main()
 {
 	int t,h,w,i,j,mx;
 	scanf("%d",&t);
	
	while(t--)
	{
 		scanf("%d %d",&h,&w);
 	memset(dp,999,sizeof(dp));
	memset(a,0,sizeof(a)); 	
 		    for (i = 1; i <= h; i++)
        {
        
		for (j = 1; j <= w; j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		
		    for (i = 1; i <= h; i++)
        {
        
		for (j = 1; j <= w; j++)
			{

			
			dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]);
}
}

for (i = 1; i <= h; i++)
        {
        
		for (j = 1; j <= w; j++)
			{
			printf("%d\t",dp[i][j]);
			}
			printf("%d\n");
		}


 mx=dp[h][1];
 for(j=2;j<=w;j++)
 	mx=min(mx,dp[h][j],999);

printf("%d\n",mx);
 
 
 }
 
 
 
 return 0;
 
}
