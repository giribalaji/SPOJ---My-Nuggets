/* A Naive recursive implementation of LCS problem */
#include<stdio.h>
#include<stdlib.h>

#define MAX 2004
int dp[2004][2004];
//int max(int a, int b);
 

/* Utility function to get max of 2 integers */
int min_1(int a, int b)
{
    return (a < b)? a : b;
}

 int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
  
/* Driver program to test above function */
int main()
{

  char Y[2004] ;
 
 char X[2004];
 int t;
 scanf("%d",&t);
 
 while(t--)
 {
 
 scanf("%s",X);
 scanf("%s",Y);
  int m = strlen(X);
  int n = strlen(Y);
 int i,j;
 for(i=0;i<=m;i++)
 {
 	for(j=0;j<=n;j++)
 	{
 		if(i==0)
 		{
 			dp[i][j]=j;
 		}
 		else if(j==0)
 		{
 			dp[i][j]=i;
 		}
 		
		 else if(X[i-1]==Y[j-1])
 		{
 			dp[i][j]=dp[i-1][j-1];
 		}
 		else
 		{
 			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
 		}
	 }
 }
 
 printf("%d\n",dp[m][n]);
 memset(dp,0,sizeof(dp[0][0]*MAX*MAX));
}
 // getchar();
  return 0;
}
