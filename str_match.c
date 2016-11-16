#include<stdio.h>
#include<string.h>
char str[4][5]={"inaq","cdef","biaks","gkty"};
char s[6]={"india"};

int dp[6][6][6]={0};
int func(int i,int j,int k, int d)
{

	if(k==5)
	{
		return 1;
	}
	if(i<0||i>3||j<0||j>3)	 
	{
		return 0;
	}

printf("Value %d %d %d %d\n",i,j,d,dp[i][j][d]);
if(dp[i][j][d]==1)
{
	return 0;
}
	dp[i][j][d]=1;
	
	if(str[i][j]==s[k])
	{
		k++;

}
	
	else
	{
		k=0;
	//	return func(i,j,k,d);
	}
if (d==0)
{


	//From left
	if(j<3)
	{
		return func(i,j+1,k,0);
	}
	
//From Down 
		if(i>0)
	{
		return func(i-1,j,k,3);
	}
//From Up
	if(i<3)
	{
		return func(i+1,j,k,2);
	}
}
else if(d==1)
{
	//From Right
	
	if(j>0)
	{
		return func(i,j-1,k,1);
	}

	
//From Down 
		if(i>0)
	{
		return func(i-1,j,k,3);
	}
//From Up
	if(i<3)
	{
		return func(i+1,j,k,2);
	}	
}

else if(d==2)
{
	//From Right
	
	if(j>0)
	{
		return func(i,j-1,k,1);
	}

	//From left
	if(j<3)
	{
		return func(i,j+1,k,0);
	}
	
//From Down 
		if(i>0)
	{
		return func(i-1,j,k,3);
	}

}

else
{
	//From Right
	
	if(j>0)
	{
		return func(i,j-1,k,1);
	}

	//From left
	if(j<3)
	{
		return func(i,j+1,k,0);
	}
	
//From Up
	if(i<3)
	{
		return func(i+1,j,k,2);
	}	


}
}
int main()
	{
		//printf("in main");
		char ch;
		int i=0,j=0,k=0,ret;
			ret=func(0,0,0,0);
			if(ret)
			printf("string  found");
			else
			printf("string not found");
		return 0;	
	}
