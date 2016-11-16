#include<stdio.h>


int arr[1005];
int mem[1005][1005]={0};
int max(int a, int b)
{
    return (a > b)? a : b;
}




int KS(n,M)
{

int i,j;
//int mem[n+1][M+1];
for(i=1;i<=n;i++)
{
	for(j=1;j<=M;j++)
	{
		
		if (i==1)
		{
			if(arr[i-1]>j)
				mem[i][j]=0;
			else
				mem[i][j]=arr[i-1];
				
		}
		else
		{
		
		if(arr[i-1]>j)
		{
		
			mem[i][j]=mem[i-1][j];
		//printf("%d\n",mem[i][j]);
	}
		else
		{
		
			mem[i][j]=max(mem[i-1][j],arr[i-1]+mem[i-2][j-arr[i-1]]);
		//	printf("%d\n",mem[i][j]);
	}
}
	}
}
	return mem[n][M];
}



int main()
{
	int t,n,k,i,j,c=0;
	//int arr[1002];
	scanf("%d",&t);
	
	
	while(t--)
	{
	c++;
	scanf("%d %d",&n,&k);
	memset(mem,0,sizeof(mem));
/*	for(i=0;i<=n;i++)
{
	for(j=0;j<=k;j++)
	{
		printf("%d\n",mem[i][j]);
	}
	
}*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int i=KS(n,k);
	printf("Scenario #%d: %d\n",c,i);
}
	return 0;
}
