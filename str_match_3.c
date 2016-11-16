#include<stdio.h>
#include<string.h>
//char str[4][5]={"inhi","kgin","liad","ajai"};
char str[4][5]={"inhi","kgdi","lina","ajan"};
char s[10]={"indian"};
//char s[10]={"nhdgij"};
int dp[6][6][6][8]={0};

typedef struct
{
  int v[10][10];
}srt;

int func(int i,int j,int k, int d, srt x)
{

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
		if (x.v[i][j]==1)
		{
//	memset(v,0,sizeof(v[0][0])*6*6);
		return 0;
		}
		k++;
	x.v[i][j]=1;
	
}
	
	else
	{
		k=0;
		memset(x.v,0,sizeof(x.v[0][0])*10*10);
	}

if (d==0)
{
	//Imcoming  way is left
	{
		return  func(i,j+1,k,0,x) || func(i-1,j,k,3,x) || func(i+1,j,k,2,x)  ;
	}

}
else if(d==1)
{
	//Incoming way is Right
	{
		return func(i,j-1,k,1,x) || func(i-1,j,k,3,x) || func(i+1,j,k,2,x) ;
	}	
}

else if(d==2)
{
	//Incoming way is Top
	{
		return func(i,j-1,k,1,x) || func(i,j+1,k,0,x) || func(i+1,j,k,2,x);
	}
}

else
{
	//Incoming way is Down
	{
		return func(i,j-1,k,1,x) ||func(i,j+1,k,0,x) || func(i-1,j,k,3,x) ;
	}
}
}

int main()
	{
		//printf("in main");
		char ch;
		int i=0,j=0,k=0,ret;
		srt x;
		//	ret=func(2,1,0,0,x);
		memset(x.v,0,sizeof(x.v[0][0])*10*10);
			ret=func(0,0,0,0,x);
			if(ret)
			printf("string  found");
			else
			printf("string not found");
		return 0;	
	}
