#include<stdio.h>
#include<string.h>
//char str[4][5]={"inhi","kgin","liad","ajai"};
char str[4][5]={"inhi","kgdi","lina","ajal"};
char s[10]={"indian"};
int dp[6][6][6][8]={0};

int func(int i,int j,int k, int d, int v[6][6])
{
if(i==1&&j==2)
{
	printf("Value %d %d  %d  %d DP = %d\n",i,j,k,d,dp[i][j][k][d]);
printf(" cell v[2][2] %d \n",v[2][2]);
}
//printf("Value %d %d  %d  %d Visited = %d\n",i,j,k,d,v[i][j]);
printf("Concerned at cell v[2][2] %d \n",v[2][2]);

//}
	if(k==6)
	{
		return 1;
	}
	if(i<0||i>3||j<0||j>3)	 
	{
//	memset(v,0,sizeof(v[0][0])*6*6);
		return 0;
	}

if(dp[i][j][k][d]==1 )
{

//memset(v,0,sizeof(v[0][0])*6*6);

	return 0;
}
	dp[i][j][k][d]=1;

	if(str[i][j]==s[k])
	{
//printf(" i = %d j = %d k = %d  v[i][j] = %d\n",i,j,k,v[i][j]);
		if (v[i][j]==1)
		{
//		printf("Visited at cell %d , %d \n",i,j);

//	memset(v,0,sizeof(v[0][0])*6*6);
//	printf(" i = %d j = %d k = %d  v[i][j] = %d\n",i,j,k,v[i][j]);
		return 0;
		}
		k++;
	v[i][j]=1;
	printf(" Match with %d %d %d\n",i,j,v[2][2]);
}
	
	else
	{
		k=0;
//printf("Value %d %d  %d  %d Visited = %d\n",i,j,k,d,v[i][j]);		
		memset(v,0,sizeof(v[0][0])*6*6);
//		int v[6][6];
//		int v={0};
	printf(" No Match %d %d %d\n",i,j,v[2][2]);
	//	return func(i,j,k,d);
	}
if (d==0)
{

printf("Concerned at cell v[2][2] %d \n",v[2][2]);
	//Imcoming  way is left
	{
		return  func(i,j+1,k,0,v) || func(i-1,j,k,3,v) || func(i+1,j,k,2,v)  ;
	}
	

}
else if(d==1)
{
	//Incoming way is Right
	

	{
		return func(i,j-1,k,1,v) || func(i-1,j,k,3,v) || func(i+1,j,k,2,v) ;
	}

	

}

else if(d==2)
{
	//Incoming way is Top
	
	
	{
		return func(i,j-1,k,1,v) || func(i,j+1,k,0,v) || func(i+1,j,k,2,v);
	}

}

else
{
	//Incoming way is Down
	

	{
		return func(i,j-1,k,1,v) ||func(i,j+1,k,0,v) || func(i-1,j,k,3,v) ;
	}



}
}
int main()
	{
		//printf("in main");
		char ch;
		int i=0,j=0,k=0,ret;
		int v[6][6];
//		memset(v,0,sizeof(v));
		memset(v,0,sizeof(v[0][0])*6*6);
//		ret=func(0,0,0,0,v);
//			ret=func(1,2,2,3);
			ret=func(2,1,0,0,v);
			if(ret)
			printf("string  found");
			else
			printf("string not found");
		return 0;	
	}
