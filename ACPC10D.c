#include<stdio.h>
#include<limits.h>
#define R 5
#define C 5
#define INT_MAX 50000 


 int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
 
 
 
 
 int main()
 {
 	long long int t,n,h,w,i,j,mx;
 //	scanf("%d",&t);
	int t1=1;
    scanf("%lld",&n);
	while(n)
	{
 		
 		long long int a[n+1][5];
 		long long int dp[n+1][5];
 	memset(dp,1000005,sizeof(dp));
	memset(a,0,sizeof(a)); 	
 	h=n;
 	w=3;
	 //rintf("%d %d\n",n,h);
	 	    for (i = 1; i <= h; i++)
        {
        
		for (j = 1; j <= w; j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		
		  
		  dp[1][2]=a[1][2];
		  dp[1][3]=a[1][2]+a[1][3];
		    for (i = 2; i <= h; i++)
        {
        
		for (j = 1; j <= w; j++)
			{

			
		//	dp[i][j]=min(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j],dp[i-1][j+1]+a[i][j]);
			dp[i][j]=a[i][j]+min(dp[i][j-1],1000008,min(dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]));
}
}

/*for (i = 0; i <= h; i++)
        {
        
		for (j = 0; j <= w; j++)
			{
			printf("%ld\t",dp[i][j]);
			}
			printf("%d\n");
		}*/



mx=dp[n][2];
printf("%d. %lld\n",t1,mx);
 scanf("%lld",&n);
 t1++;
 }
 
 
 
 return 0;
 
}
