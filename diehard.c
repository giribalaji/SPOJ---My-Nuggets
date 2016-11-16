#include<stdio.h>

int dp[1005][1005][5]={0};


 int max(int x, int y, int z)
{
   if (x > y)
      return (x > z)? x : z;
   else
      return (y > z)? y : z;
}


int diehard(int a,int h,int f)
{
	
	
	//printf("%d",dp[a][h]);
	if(a<=0 || h<=0)
		return 0; 
	
	/*if(a==0 || h==0)
	{
		dp[a][h][f]=0;	
		return 0;
}*/
	if(dp[a][h][f]==-1)
	{
	if(f==-1)
	{
		dp[a][h][f]=(max(diehard(a+3,h+2,1),diehard(a-5,h-10,2),diehard(a-20,h+5,3)));
		return dp[a][h][f];
	}

	if(f==1)
	{
		dp[a][h][f]=(1+max(diehard(a-5,h-10,2),diehard(a-20,h+5,3),0));
		return dp[a][h][f];
	}
	if(f==2)
	{
		dp[a][h][f]=(1+max(diehard(a+3,h+2,1),0,diehard(a-20,h+5,3)));
		return dp[a][h][f];
	}
	
if(f==3)
	{
		dp[a][h][f]=(1+max(diehard(a+3,h+2,1),diehard(a-5,h-10,2),0));
		return dp[a][h][f];
	}


}
else
	return dp[a][h][f];
}




 int main()
 {
 	int t,h,w,i,j,mx;
 	scanf("%d",&t);
	//memset(dp,-1,(1005*1005*5));
	memset(dp,-1,sizeof(dp));
	//printf("%d\n",sizeof(dp));
	while(t--)
	{
 		scanf("%d %d",&h,&w);
 		printf("%d\n",diehard(h,w,-1));
 		
 		memset(dp,-1,sizeof(dp));
 	}
 	
 	
 	return 0;
 }
