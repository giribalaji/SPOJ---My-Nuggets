#include<string.h>
#include<math.h>
#include<stdio.h>
int k;
int dp[2005][2005]={0};
int min(int a, int b,int c)
{
    if(a<b)
    	if(a<c)
    		return a;
    	else
    		return c;
    else if(b<c)
    	return b;
    else
    	return c;
}

int fun(char*s1,char*s2,int m1,int n1)
{
//printf("%d   %d\n",m,n);
if(m1==0||n1==0)
	return 0;
//int dp[m1+1][n1+1];
//memset(dp,0,sizeof(dp));

int i,j,m,n;
for(i=1;i<=m1;i++)
	dp[i][0]=i*k;

for(i=1;i<=n1;i++)
	dp[0][i]=i*k;
	
for(m=1;m<=m1;m++)
{
for(n=1;n<=n1;n++)
{

if(s1[m-1]==s2[n-1])
{
//printf("here %c  %c\n",s1[m],s2[n]);

	dp[m][n] =dp[m-1][n-1];
//	printf("%d \n",dp[m][n]);
}
else

	dp[m][n]=min(k+dp[m][n-1],k+dp[m-1][n],abs(s1[m-1]-s2[n-1])+dp[m-1][n-1]);
//	printf("%d \n",dp[m][n]);
}
}
return dp[m1][n1];
}


int main()
{
	
	while(1)
	{
	char arr1[2005],arr2[2005];
	char*s1=arr1,*s2=arr2;
	scanf("%s",s1);
	scanf("%s",s2);
	int k1,m,n;
	scanf("%d",&k);
	m=strlen(s1),n=strlen(s2);
	printf("%d\n",fun(s1,s2,m,n));
}
	return 0;
}
