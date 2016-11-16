#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 205  
long long int A[205];
long long int B[205];
int dp[205][205];
static int count;

int rec(m,n)
{
	int count=0,i;
	if(n==0 && m==-1)
	{
	//printf("Values %d %d \n",A[m+1],B[m+1]);
		return 1;
	}
	if(m<0||n<0)
	{
		return 0;
	}

if(dp[m][n]!=-1)
{
	return dp[m][n]; 
}
for(i=A[m];i<=B[m];i++)
{
//	printf("Values %d %d \n",m,n-i);
	count=count+rec(m-1,n-i);
}
return dp[m][n]=count;
}


int main()
{
 int m,n,i,j,t;
 
 scanf("%d",&t);
 
 while(t--)
    {
memset(dp,-1,sizeof(dp[0][0])*MAX*MAX);
 	scanf("%d %d",&m,&n);
for(i=0;i<m;i++)	 
{
	scanf("%ld %ld",&A[i],&B[i]);
	}
	 
printf("%d\n",rec(m-1,n)); 
 	
//scanf("%d %d",&m,&n);
 }



	return 0;
}
