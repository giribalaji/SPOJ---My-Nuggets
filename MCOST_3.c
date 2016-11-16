#include<stdio.h>

char sa[1003];
char ta[1003];
char *s=sa,*t=ta;
int dp[1005][1005];
int min(int a, int b)
{
    return (a < b)? a : b;
}


int KS(int n,int M)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(s[i-1] == t[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=min(15+dp[i-1][j],30+dp[i][j-1]);
			}
		}
	}
return dp[n][M];
}


int main()
{
	int n,k,i,j,c=0;
	
//	scanf("%d",&t);
		
	while(1)
	{
	scanf("%s",s);
	scanf("%s",t);
	printf("%s %s %c\n",s,t,s[0]);
	if(s[0]=='#')
	{
		break;
	}
	else
	{
	
	memset(dp,0,sizeof(dp));
/*for (i = 1; i < 1005; i++){
		dp[i][0] = i * 15;
		dp[0][i] = i * 30;
	}*/
	n=strlen(s);
	k=strlen(t);
	int i=KS(n,k);
	
	printf("Hey stupid robber, you can get %d.\n",i);
}
}
	return 0;
}
